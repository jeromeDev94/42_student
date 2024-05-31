filetype plugin indent on
syntax enable
colorscheme onehalfdark

set nocompatible
set signcolumn=yes
set noexpandtab
set tabstop=4
set shiftwidth=4
set mouse=a
set number
set cursorline
set foldmethod=manual
set incsearch  
set hlsearch  
set splitbelow
set splitright
set hidden
set history=200
set scrolloff=8
set wildmenu

let g:user42 = 'jeportie'
let g:mail42 = 'jeportie@student.42.fr'
let g:openai_api_key='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'
let g:chat_gpt_max_tokens=8192
let g:chat_gpt_model='gpt-4'
"let g:chat_gpt_session_mode=0
let g:chat_gpt_temperature = 0.7
let g:chat_gpt_lang = 'English'
"let g:chat_gpt_split_direction = 'vertical'
"***********MAPPING*******************
"VIM
nnoremap <Leader>l :execute "normal! i#include \"libft.h\""<CR>
nnoremap <F12> :execute "normal! iprintf(\"\\n\");"<CR>
nnoremap <leader>u :NERDTreeRefreshRoot<CR>
nnoremap <leader>bd :bdelete<CR>
nnoremap <leader>s :split<CR>
nnoremap <leader>vs :vertical split<CR>
nnoremap <leader>t :terminal<CR>
nnoremap <leader>vt :vertical terminal<CR>
nnoremap <leader>r :set relativenumber<CR>
nnoremap <leader>nr :set norelativenumber<CR>
nnoremap <Leader>cc :set colorcolumn=80<CR>
nnoremap <Leader>ncc :set colorcolumn-=80<CR>
nnoremap <leader>L :set list!<CR> 
nnoremap <c-h> :set hlsearch!<CR>
"Plugins
nnoremap <F2> :NERDTreeToggle<CR>
nmap <F3> :TagbarToggle<CR>
nnoremap <F4> :Files<CR>
nnoremap <C-M> :bnext<CR>
nnoremap <C-N> :bprev<CR>

"***********PLUGINS*******************
"=================================================================================================

" Set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
" Download plug-ins to the ~/.vim/plugged/ directory
call vundle#begin('~/.vim/plugged')
" Let Vundle manage Vundle
Plugin 'VundleVim/Vundle.vim'
call vundle#end()

"=================================================================================================

Plugin 'sheerun/vim-polyglot'
Plugin 'dense-analysis/ale'
Plugin 'ap/vim-buftabline'
Plugin 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plugin 'junegunn/fzf.vim'
Plugin 'airblade/vim-rooter'
Plugin 'jiangmiao/auto-pairs'
let g:AutoPairsShortcutToggle = '<C-P>'
Plugin 'mattn/emmet-vim'
let g:user_emmet_leader_key=','

"=================================================================================================

Plugin 'preservim/nerdtree'
let NERDTreeShowBookmarks = 1   " Show the bookmarks table
let NERDTreeShowHidden = 1      " Show hidden files
let NERDTreeShowLineNumbers = 0 " Hide line numbers
let NERDTreeMinimalMenu = 1     " Use the minimal menu (m)
let NERDTreeWinSize = 31        " Set panel width to 31 columns
" Start NERDTree. If a file is specified, move the cursor to its window.
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * NERDTree | if argc() > 0 || exists("s:std_in") | wincmd p | endif
" Open the existing NERDTree on each new tab.
autocmd BufWinEnter * if getcmdwintype() == '' | silent NERDTreeMirror | endif
" Exit Vim if NERDTree is the only window remaining in the only tab.
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif

"=================================================================================================

Plugin 'preservim/tagbar'
" Focus the panel when opening it
let g:tagbar_autofocus = 1
" Highlight the active tag
let g:tagbar_autoshowtag = 1
" Make panel vertical and place on the right
let g:tagbar_position = 'botright vertical'
" Mapping to open and close the panel

"=================================================================================================

"Plugin 'ycm-core/YouCompleteMe'
"" Mapping to close the completion menu (default <C-y>)
"let g:ycm_key_list_select_completion = ['<C-]>']
"let g:ycm_key_list_stop_completion = ['<C-x>']
"" Set filetypes where YCM will be turned on
"let g:ycm_filetype_whitelist = { 'cpp':1, 'h':2, 'hpp':3, 'c':4, 'cxx':5 }
"" Close preview window after completing the insertion
"let g:ycm_autoclose_preview_window_after_insertion = 1
"let g:ycm_autoclose_preview_window_after_completion = 1
"let g:ycm_confirm_extra_conf = 0                 " Don't confirm python conf
"let g:ycm_always_populate_location_list = 1      " Always populae diagnostics list
"let g:ycm_enable_diagnostic_signs = 1            " Enable line highligting diagnostics
"let g:ycm_open_loclist_on_ycm_diags = 1          " Open location list to view diagnostics
"let g:ycm_max_num_candidates = 20                " Max number of completion suggestions 
"let g:ycm_max_num_identifier_candidates = 10     " Max number of identifier-based suggestions
"let g:ycm_auto_trigger = 1                       " Enable completion menu
"let g:ycm_show_diagnostic_ui = 1                 " Show diagnostic display features
"let g:ycm_error_symbol = '>>'                    " The error symbol in Vim gutter
"let g:ycm_enable_diagnostic_signs = 1            " Display icons in Vim's gutter, error, warnings
"let g:ycm_enable_diagnostic_highlighting = 1     " Highlight regions of diagnostic text
"let g:ycm_echo_current_diagnostic = 1            " Echo line's diagnostic that cursor is on
