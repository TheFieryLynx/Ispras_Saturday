## NovelSorting

This program is line-by-line sorting of any .txt file
As an example you can sort a novel by Alexander Pushkin - Eugene Onegin
File with the novel is in Docs folder.
Name of the .txt file: Onegin.txt

To compile this project:
```
make
```

To run this this program:
```
./run [KEYS] [PATHFILE]
```
KEYS:
1. `-orig` - if you want to create file with the original text
2. `-alph` - creates file with sorted text in alphabetical order
3. `-rhm` - creates file with sorted text in rhyme order
4. `-all` - creates all files: in arithmetical order, rhyme order and original

**All keys can be listed in any order and in any number**

PATHFILE: path to the file which you want to sort. For example, you can specify a file in folder Docs in this project: *Docs/onegin.txt*