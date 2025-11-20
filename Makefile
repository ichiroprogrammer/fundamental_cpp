MAKEFILE:=$(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST))

TARGET:=o/fundamental_cpp.md
TITLE=Fundamental  Knowledge of C++($(VERSION))

#MD_SEC_NUM:=--sec_num

MD_GEN:=./md_gen/export/py

VPATH=./md:essential/md:deep/md/:comprehensive/md

MDS:=fundamental_intro.md cpp03_syntax.md cpp_improve.md temp.md \
	 core_lang_spec.md stdlib_and_concepts.md cpp_idioms.md 

INDEX_OPT:=--exclude $(addsuffix :1,$(MDS) sample_code.md)

include deep/make/md.mk

