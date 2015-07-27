/*****************************************************************************/
/* stdarg.h   v2.0.0B2                                                       */
/*                                                                           */
/* Copyright (c) 2013-2014 Texas Instruments Incorporated                    */
/* http://www.ti.com/                                                        */
/*                                                                           */
/*  Redistribution and  use in source  and binary forms, with  or without    */
/*  modification,  are permitted provided  that the  following conditions    */
/*  are met:                                                                 */
/*                                                                           */
/*     Redistributions  of source  code must  retain the  above copyright    */
/*     notice, this list of conditions and the following disclaimer.         */
/*                                                                           */
/*     Redistributions in binary form  must reproduce the above copyright    */
/*     notice, this  list of conditions  and the following  disclaimer in    */
/*     the  documentation  and/or   other  materials  provided  with  the    */
/*     distribution.                                                         */
/*                                                                           */
/*     Neither the  name of Texas Instruments Incorporated  nor the names    */
/*     of its  contributors may  be used to  endorse or  promote products    */
/*     derived  from   this  software  without   specific  prior  written    */
/*     permission.                                                           */
/*                                                                           */
/*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS    */
/*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT    */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR    */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT    */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    */
/*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT    */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,    */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY    */
/*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     */
/*                                                                           */
/*****************************************************************************/

#ifndef _STDARG
#define _STDARG

#ifdef __cplusplus
#define _NS_PREFIX std::
namespace std {
#else
#define _NS_PREFIX
#endif /* __cplusplus */

typedef struct __va_list {
    void * __ap;
} va_list;

#ifdef __cplusplus
} /* namespace std */
#endif


#define va_start(ap, parmN)						      \
    ((ap).__ap = ((void *)((int)__va_parmadr(parmN) + sizeof(parmN))))

#define va_arg(_ap, _type)                                                    \
    (( (_ap).__ap = (void *) ((unsigned int)(_ap).__ap + sizeof(_type)) ),    \
     (*((_type*)((unsigned int)(_ap).__ap - sizeof(_type)))))

#define va_end(ap) ((void)0)

#endif /* _STDARG */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)
using std::va_list;
#endif /* _CPP_STYLE_HEADER */
