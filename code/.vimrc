let mapleader = "\"

syntax on
filetype plugin on

set nocompatible
set autoread
set foldmethod=marker
set autoindent
set clipboard+=unnamedplus
set encoding=utf-8
set number relativenumber
set shiftwidth=2 softtabstop=2 expandtab

map <leader>c :w! && !compile %<CR>
vmap < <gv
vmap > >gv
nmap Y y$
