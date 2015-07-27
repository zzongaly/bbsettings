##############################################################################
#
#
# Makefile for PRU run-time support library version 2.0.0B2
#
#
##############################################################################
#
# This Makefile is automatically-generated: you usually should not edit it. 
#
##############################################################################


##############################################################################
#
# This Makefile is specific to compiler RTS library version 2.0.0B2.  
# The format is subject to change without notice.  This Makefile is intended
# for use with mklib, which understands which 'make' variables to set to build
# each distinct version of the RTS library.
#
# This Makefile uses GNU make language extensions.
#
##############################################################################

##############################################################################
#
# GROUPS
#
# The source files are set up in a modular fashion using "groups."  Groups
# represent major feature clusters, and usually specify source files which
# implement that feature.  When building a library which needs a particular
# feature, the group which represents that feature is "activated" by setting a
# 'make' variable.  This variable can be set directly by the user, or may be
# inferred from the setting of other variables.  Groups (and the files they
# contain) not needed for a certain library are not activated.  Some groups
# are always activated.  Groups which are not always activated are enclosed in
# an "ifeq" testing the corresponding 'make' variable (the name of the
# variable is the name of the group).
#
# Groups can specify any kind of source file (e.g. C, C++, assembly), but do
# not list header files, or source files included from other source files.
# This Makefile is focused on how to build the object files, not listing all
# of the necessary files.  Some groups do not list any source files; these
# groups may still carry information such as extra options to use when that
# group is active, or may activate other groups.  Some groups exist only to be
# tested as part of the activation condition of other groups.
#
# Groups can specify extra compiler options to use when that group is active.
# These can be options intended for all targets (UNIVERSAL_FLAGS), such as the
# CPU version, or can be intended only for a certain type of files (CPP_FLAGS)
# (e.g. the option "--exceptions")
#
##############################################################################

##############################################################################
#
# OPTIONS
#
# You can append or override some options through 'make' variables specified
# on the command line.  Not all options can be changed this way, and some
# options are dangerous to use in a Makefile (e.g. "--skip_assembler").
# Options added by groups below should not be altered; if the option is
# undesired, you're probably building the wrong library.  For example, if you
# don't want "--exceptions", you shouldn't be using EXCEPTIONS=1.
#
# You can append options to the standard list by using EXTRA_FLAGS.  This is
# useful for enabling debugging support or activating silicon errata
# workarounds:
#
# gmake LIB=some.lib EXTRA_FLAGS="-g"
#
# You can completely replace the standard list by using STANDARD_FLAGS, but
# this should almost never be necessary.  WARNING: This Makefile will not
# optimize the files if you replace the standard list and your replacement
# options do not include the right optimization flags.
#
# gmake LIB=some.lib STANDARD_FLAGS="-o3 -oe"
#
##############################################################################

##############################################################################
# Available libraries
#
# You can build each 2.0.0B2 library using the appropriate command:
#
# gmake library LIB=rtspruv1_be.lib BIG_ENDIAN=1 V1=1
# gmake library LIB=rtspruv1_be_eh.lib FULL_PORTABLE_EH=1 BIG_ENDIAN=1 EXCEPTIONS=1 V1=1
# gmake library LIB=rtspruv1_le.lib V1=1 LITTLE_ENDIAN=1
# gmake library LIB=rtspruv1_le_eh.lib FULL_PORTABLE_EH=1 EXCEPTIONS=1 V1=1 LITTLE_ENDIAN=1
# gmake library LIB=rtspruv2_be.lib BIG_ENDIAN=1 V2=1
# gmake library LIB=rtspruv2_be_eh.lib FULL_PORTABLE_EH=1 BIG_ENDIAN=1 EXCEPTIONS=1 V2=1
# gmake library LIB=rtspruv2_le.lib V2=1 LITTLE_ENDIAN=1
# gmake library LIB=rtspruv2_le_eh.lib FULL_PORTABLE_EH=1 EXCEPTIONS=1 V2=1 LITTLE_ENDIAN=1
# gmake library LIB=rtspruv3_be.lib V3=1 BIG_ENDIAN=1
# gmake library LIB=rtspruv3_be_eh.lib FULL_PORTABLE_EH=1 V3=1 BIG_ENDIAN=1 EXCEPTIONS=1
# gmake library LIB=rtspruv3_le.lib V3=1 LITTLE_ENDIAN=1
# gmake library LIB=rtspruv3_le_eh.lib FULL_PORTABLE_EH=1 V3=1 EXCEPTIONS=1 LITTLE_ENDIAN=1
##############################################################################

#-----------------------------------------------------------------------------
# Basic definitions
#-----------------------------------------------------------------------------
STANDARD_FLAGS =  -O --embed_icode --keep_asm --diag_warning=225 --quiet
ifeq (y,$(shell [ -e $(CGT_BIN)/clpru ] && echo y))
  CC = $(CGT_BIN)/clpru
else
  CC = clpru
endif
ifeq (y,$(shell [ -e $(CGT_BIN)/arpru ] && echo y))
  AR = $(CGT_BIN)/arpru
else
  AR = arpru
endif
CD = cd

OBJ = OBJ

#-----------------------------------------------------------------------------
# Group TARGET
#-----------------------------------------------------------------------------
UNIVERSAL_FLAGS += --mem_model:data=far

TARGET_C_SOURCE = \
	boot.c \
	boot_special.c \
	autoinit.c \
	llmpy.c \
	mpyi.c \
	imath64.c \
	asri.c \
	divi_c.c \
	divu_c.c \
	remi_c.c \
	remu_c.c \
	trgmsg.c \
	copy_zero_init.c \
	copy_decompress_none.c \
	copy_decompress_rle.c \
	copy_decompress_lzss.c

C_SOURCE += $(TARGET_C_SOURCE)


TARGET_ASM_SOURCE = \
	memcpy.asm \
	setjmp.asm

ASM_SOURCE += $(TARGET_ASM_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_MATH_BASIC_DOUBLE_IS_64
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_BASIC_FLOAT
#-----------------------------------------------------------------------------

GENERIC_MATH_BASIC_FLOAT_C_SOURCE = \
	addf.c \
	cmpf.c \
	cvtdf.c \
	divf.c \
	fixfi.c \
	fixfli.c \
	fixflli.c \
	fixfu.c \
	fixful.c \
	fixfull.c \
	fltif.c \
	fltlif.c \
	fltllif.c \
	fltuf.c \
	fltulf.c \
	fltullf.c \
	frcaddf.c \
	frcdivf.c \
	frcmpyf.c \
	frcmpyf_div.c \
	mpyf.c \
	negf.c \
	renormf.c \
	subf.c

C_SOURCE += $(GENERIC_MATH_BASIC_FLOAT_C_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_MATH_BASIC_DOUBLE
#-----------------------------------------------------------------------------

GENERIC_MATH_BASIC_DOUBLE_C_SOURCE = \
	addd.c \
	cmpd.c \
	cvtfd.c \
	divd.c \
	fixdi.c \
	fixdli.c \
	fixdlli.c \
	fixdu.c \
	fixdul.c \
	fixdull.c \
	fltid.c \
	fltlid.c \
	fltllid.c \
	fltud.c \
	fltuld.c \
	fltulld.c \
	frcaddd.c \
	frcdivd.c \
	frcmpyd.c \
	frcmpyd_div.c \
	mpyd.c \
	negd.c \
	renormd.c \
	subd.c

C_SOURCE += $(GENERIC_MATH_BASIC_DOUBLE_C_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC
#-----------------------------------------------------------------------------
UNIVERSAL_FLAGS += -c --ti_lib --building_runtime -D_BOOL --keep_unneeded_types=false
CPP_FLAGS += -fg --rtti

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON_64BIT
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON_32BIT
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON_FLOAT
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON_DOUBLE
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group DINKUM_MATH
#-----------------------------------------------------------------------------

DINKUM_MATH_C_SOURCE = \
	ldexp.c \
	ldexpf.c \
	ldexpl.c \
	frexp.c \
	frexpf.c \
	frexpl.c \
	acos.c \
	acosf.c \
	acosl.c \
	asin.c \
	asinf.c \
	asinl.c \
	atan.c \
	atanf.c \
	atanl.c \
	xatan.c \
	xfatan.c \
	xlatan.c \
	atan2.c \
	atan2f.c \
	atan2l.c \
	ceil.c \
	ceilf.c \
	ceill.c \
	cos.c \
	cosf.c \
	cosl.c \
	cosh.c \
	coshf.c \
	coshl.c \
	sqrt.c \
	sqrtf.c \
	sqrtl.c \
	exp.c \
	expf.c \
	expl.c \
	exp2.c \
	exp2f.c \
	exp2l.c \
	fabs.c \
	fabsf.c \
	fabsl.c \
	floor.c \
	floorf.c \
	floorl.c \
	modf.c \
	modff.c \
	modfl.c \
	fmod.c \
	fmodf.c \
	fmodl.c \
	log.c \
	logf.c \
	logl.c \
	xlog.c \
	xflog.c \
	xllog.c \
	log10.c \
	log10f.c \
	log10l.c \
	log2.c \
	log2f.c \
	log2l.c \
	logb.c \
	logbf.c \
	logbl.c \
	ilogb.c \
	ilogbf.c \
	ilogbl.c \
	pow.c \
	powf.c \
	powl.c \
	sin.c \
	sinf.c \
	sinl.c \
	sinh.c \
	sinhf.c \
	sinhl.c \
	tan.c \
	tanf.c \
	tanl.c \
	tanh.c \
	tanhf.c \
	tanhl.c \
	xdint.c \
	xfdint.c \
	xldint.c \
	xdunscal.c \
	xfdunsca.c \
	xldunsca.c \
	xdclass.c \
	xfdclass.c \
	xldclass.c \
	feraiseexcept.c \
	feupdateenv.c \
	acosh.c \
	acoshf.c \
	acoshl.c \
	asinh.c \
	asinhf.c \
	asinhl.c \
	atanh.c \
	atanhf.c \
	atanhl.c \
	trunc.c \
	truncf.c \
	truncl.c \
	round.c \
	roundf.c \
	roundl.c \
	lround.c \
	lroundf.c \
	lroundl.c \
	llround.c \
	llroundf.c \
	llroundl.c \
	nearbyint.c \
	nearbyintf.c \
	nearbyintl.c \
	nextafter.c \
	nextafterf.c \
	nextafterl.c \
	nexttoward.c \
	nexttowardf.c \
	nexttowardl.c \
	fma.c \
	fmaf.c \
	fmal.c \
	fmax.c \
	fmaxf.c \
	fmaxl.c \
	fmin.c \
	fminf.c \
	fminl.c \
	fdim.c \
	fdimf.c \
	fdiml.c \
	copysign.c \
	copysignf.c \
	copysignl.c \
	scalbn.c \
	scalbnf.c \
	scalbnl.c \
	scalbln.c \
	scalblnf.c \
	scalblnl.c \
	cbrt.c \
	cbrtf.c \
	cbrtl.c \
	erf.c \
	erff.c \
	erfl.c \
	erfc.c \
	erfcf.c \
	erfcl.c \
	xerfc.c \
	xferfc.c \
	xlerfc.c \
	expm1.c \
	expm1f.c \
	expm1l.c \
	lgamma.c \
	lgammaf.c \
	lgammal.c \
	xlgamma.c \
	xflgamma.c \
	xllgamma.c \
	tgamma.c \
	tgammaf.c \
	tgammal.c \
	xtgamma.c \
	xftgamma.c \
	xltgamma.c \
	nan.c \
	nanf.c \
	nanl.c \
	rint.c \
	rintf.c \
	rintl.c \
	lrint.c \
	lrintf.c \
	lrintl.c \
	llrint.c \
	llrintf.c \
	llrintl.c \
	remainder.c \
	remainderf.c \
	remainderl.c \
	remquo.c \
	remquof.c \
	remquol.c \
	feclearexcept.c \
	feholdexcept.c \
	fesetenv.c \
	fetestexcept.c \
	fegetexceptflag.c \
	fesetexceptflag.c \
	xfpcomp.c \
	xffpcomp.c \
	xlfpcomp.c \
	xdsign.c \
	xfdsign.c \
	xldsign.c \
	imaxabs.c \
	abs.c \
	labs.c \
	llabs.c \
	imaxdiv.c \
	div.c \
	ldiv.c \
	lldiv.c

C_SOURCE += $(DINKUM_MATH_C_SOURCE)


DINKUM_MATH_CX_SOURCE = \
	xerrno.cx

CX_SOURCE += $(DINKUM_MATH_CX_SOURCE)


#-----------------------------------------------------------------------------
# Group EXCEPTIONS
#-----------------------------------------------------------------------------
ifeq ($(EXCEPTIONS),1)
CPP_FLAGS += --exceptions
endif


#-----------------------------------------------------------------------------
# Group COMPLEX_HEADERS
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group DINKUM_MATH_SUBSET_SHARED_WITH_COMPLEX
#-----------------------------------------------------------------------------

DINKUM_MATH_SUBSET_SHARED_WITH_COMPLEX_C_SOURCE = \
	xsin.c \
	xfsin.c \
	xlsin.c \
	xsinh.c \
	xfsinh.c \
	xlsinh.c \
	xcosh.c \
	xfcosh.c \
	xlcosh.c \
	xexp.c \
	xfexp.c \
	xlexp.c \
	xdscale.c \
	xfdscale.c \
	xldscale.c \
	xdnorm.c \
	xfdnorm.c \
	xldnorm.c \
	xvalues.c \
	xfvalues.c \
	xlvalues.c \
	xferaise.c \
	xhypot.c \
	xfhypot.c \
	xlhypot.c \
	hypot.c \
	hypotf.c \
	hypotl.c \
	log1p.c \
	log1pf.c \
	log1pl.c \
	xpoly.c \
	xfpoly.c \
	xlpoly.c

C_SOURCE += $(DINKUM_MATH_SUBSET_SHARED_WITH_COMPLEX_C_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_TI
#-----------------------------------------------------------------------------

GENERIC_TI_C_SOURCE = \
	cpy_tbl.c \
	ecvt.c \
	exit.c \
	fcvt.c \
	memory.c \
	_bufread.c \
	_data_synch.c \
	_io_perm.c \
	_lock.c \
	_mutex.c \
	_printfi.c \
	_printfi_min.c \
	_printfi_nf.c \
	_pthread.c \
	_scanfi.c \
	_scanfi_min.c \
	_scanfi_nf.c \
	_tvaltostr.c \
	args_main.c \
	asctime.c \
	assert.c \
	atexit.c \
	atof.c \
	atoi.c \
	atol.c \
	atoll.c \
	bcmp.c \
	bcopy.c \
	bsearch.c \
	bzero.c \
	clearerr.c \
	clock.c \
	ctime_.c \
	ctype.c \
	defs.c \
	difftime.c \
	errno.c \
	fclose.c \
	feof.c \
	ferror.c \
	fflush.c \
	ffs.c \
	fgetc.c \
	fgetpos.c \
	fgets.c \
	fopen.c \
	fprintf.c \
	fputc.c \
	fputs.c \
	fread.c \
	fscanf.c \
	fseek.c \
	fsetpos.c \
	ftell.c \
	fwrite.c \
	getenv.c \
	gmtime.c \
	index.c \
	isalnum.c \
	isalpha.c \
	isascii.c \
	iscntrl.c \
	isdigit.c \
	isgraph.c \
	islower.c \
	isprint.c \
	ispunct.c \
	isspace.c \
	isupper.c \
	isxdigit.c \
	localtim.c \
	lowlev.c \
	ltoa.c \
	memccpy.c \
	memchr.c \
	memcmp.c \
	memmov.c \
	memset.c \
	mktime.c \
	multibyte.c \
	perror.c \
	printf.c \
	qsort.c \
	rand.c \
	remove.c \
	rewind.c \
	rindex.c \
	setbuf.c \
	setlocale.c \
	setvbuf.c \
	sinit.c \
	snprintf.c \
	sprintf.c \
	sscanf.c \
	strcasecmp.c \
	strcat.c \
	strchr.c \
	strcmp.c \
	strcoll.c \
	strcpy.c \
	strcspn.c \
	strdup.c \
	strerror.c \
	strftime.c \
	strlen.c \
	strncasecmp.c \
	strncat.c \
	strncmp.c \
	strncpy.c \
	strpbrk.c \
	strrchr.c \
	strspn.c \
	strstr.c \
	strtod.c \
	strtok.c \
	strtol.c \
	strtold.c \
	strtoll.c \
	strtoul.c \
	strtoull.c \
	strtoimax.c \
	strtoumax.c \
	strxfrm.c \
	time.c \
	tmpfile.c \
	tmpnam.c \
	tmzone.c \
	toascii.c \
	tolower.c \
	toupper.c \
	trgdrv.c \
	ungetc.c \
	vfprintf.c \
	vprintf.c \
	vsnprintf.c \
	vsprintf.c \
	wctype.c

C_SOURCE += $(GENERIC_TI_C_SOURCE)


#-----------------------------------------------------------------------------
# Group GENERIC_EDG
#-----------------------------------------------------------------------------

GENERIC_EDG_CPP_SOURCE = \
	array_del.cpp \
	array_new.cpp \
	array_nodel.cpp \
	array_nonew.cpp \
	array_pdel.cpp \
	array_pnew.cpp \
	delete.cpp \
	delnothrow.cpp \
	dtor_list.cpp \
	error.cpp \
	guard.cpp \
	memzero.cpp \
	new_.cpp \
	newhandler.cpp \
	newnothrow.cpp \
	placedel.cpp \
	placenew.cpp \
	pure_virt.cpp \
	rtti.cpp \
	set_new.cpp \
	typeinfo_.cpp \
	vars.cpp \
	vec_cctor.cpp \
	vec_newdel.cpp \
	vla_alloc.cpp

CPP_SOURCE += $(GENERIC_EDG_CPP_SOURCE)


#-----------------------------------------------------------------------------
# Group V2
#-----------------------------------------------------------------------------
ifeq ($(V2),1)
UNIVERSAL_FLAGS += -v2
endif


#-----------------------------------------------------------------------------
# Group LITTLE_ENDIAN
#-----------------------------------------------------------------------------
ifeq ($(LITTLE_ENDIAN),1)
UNIVERSAL_FLAGS += --endian=little
endif


#-----------------------------------------------------------------------------
# Group GENERIC_MATH_COMMON
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Group V1
#-----------------------------------------------------------------------------
ifeq ($(V1),1)
UNIVERSAL_FLAGS += -v1
endif


#-----------------------------------------------------------------------------
# Group GENERIC_DINKUM
#-----------------------------------------------------------------------------

GENERIC_DINKUM_C_SOURCE = \
	signal.c \
	raise.c \
	fwide.c \
	stox.c

C_SOURCE += $(GENERIC_DINKUM_C_SOURCE)


GENERIC_DINKUM_CPP_SOURCE = \
	fiopen.cpp \
	iomanip.cpp \
	ios.cpp \
	iostream.cpp \
	limits.cpp \
	locale.cpp \
	locale0.cpp \
	nothrow.cpp \
	raisehan.cpp \
	string.cpp \
	strstrea.cpp \
	throw.cpp \
	wiostrea.cpp \
	wlocale.cpp \
	xfpostox.cpp \
	xlocale.cpp \
	xlocinfo.cpp

CPP_SOURCE += $(GENERIC_DINKUM_CPP_SOURCE)


GENERIC_DINKUM_CX0_SOURCE = \
	xatexit.cx0

CX0_SOURCE += $(GENERIC_DINKUM_CX0_SOURCE)


GENERIC_DINKUM_CX_SOURCE = \
	wchar.cx

CX_SOURCE += $(GENERIC_DINKUM_CX_SOURCE)


#-----------------------------------------------------------------------------
# Group BIG_ENDIAN
#-----------------------------------------------------------------------------
ifeq ($(BIG_ENDIAN),1)
UNIVERSAL_FLAGS += --endian=big
endif


#-----------------------------------------------------------------------------
# Group V3
#-----------------------------------------------------------------------------
ifeq ($(V3),1)
UNIVERSAL_FLAGS += -v3
endif


#-----------------------------------------------------------------------------
# Group FULL_PORTABLE_EH
#-----------------------------------------------------------------------------
ifeq ($(EXCEPTIONS),1)
FULL_PORTABLE_EH=1
endif

ifeq ($(FULL_PORTABLE_EH),1)

FULL_PORTABLE_EH_CPP_SOURCE = \
	eh_util.cpp \
	throw_edg.cpp

CPP_SOURCE += $(FULL_PORTABLE_EH_CPP_SOURCE)

endif



C_OBJS = $(patsubst %.c,$(OBJ)/%.obj,$(notdir $(C_SOURCE)))

$(C_OBJS): $(OBJ)/%.obj: %.c
	$(CC) $^ $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(C_FLAGS) -I$(INC) -fr $(OBJ) -fs $(OBJ) -ft $(OBJ)

ASM_OBJS = $(patsubst %.asm,$(OBJ)/%.obj,$(notdir $(ASM_SOURCE)))

$(ASM_OBJS): $(OBJ)/%.obj: %.asm
	$(CC) $^ $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(C_FLAGS) -I$(INC) -fr $(OBJ) -fs $(OBJ) -ft $(OBJ)

CX0_OBJS = $(patsubst %.cx0,$(OBJ)/%.obj,$(notdir $(CX0_SOURCE)))

$(CX0_OBJS): $(OBJ)/%.obj: %.cx0
	$(CC) $^ $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(C_FLAGS) -I$(INC) -fr $(OBJ) -fs $(OBJ) -ft $(OBJ)

CX_OBJS = $(patsubst %.cx,$(OBJ)/%.obj,$(notdir $(CX_SOURCE)))

$(CX_OBJS): $(OBJ)/%.obj: %.cx
	$(CC) $^ $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(C_FLAGS) -I$(INC) -fr $(OBJ) -fs $(OBJ) -ft $(OBJ)

CPP_OBJS = $(patsubst %.cpp,$(OBJ)/%.obj,$(notdir $(CPP_SOURCE)))

$(CPP_OBJS): $(OBJ)/%.obj: %.cpp
	$(CC) $^ $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(UNIVERSAL_FLAGS) $(CPP_FLAGS) -I$(INC) -fr $(OBJ) -fs $(OBJ) -ft $(OBJ)

library: $(C_OBJS) $(ASM_OBJS) $(CX0_OBJS) $(CX_OBJS) $(CPP_OBJS)
	$(CD) $(OBJ); $(AR) -qa $(LIB) *.obj

info:
	@echo $(UNIVERSAL_FLAGS)
	@echo $(STANDARD_FLAGS)
	@echo $(EXTRA_FLAGS)
	@echo $(C_FLAGS)
	@echo $(CPP_FLAGS)
	@echo
	@echo $(C_OBJS)
	@echo $(CPP_OBJS)
