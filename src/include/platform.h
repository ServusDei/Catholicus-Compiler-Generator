/*
 * file: platform.h
 * origin: platform.h.in
 * author: Andrew Thomas Porter <caritasdedeus@gmail.com>
 * description:
 */

#ifndef INCLUDE_PLATFORM_H_
#define INCLUDE_PLATFORM_H_

#include <stddef.h>
#include "macro.h"

// VARIABLES:

// ENVIRONMENT
// ENVIRONMENT_NAME
// ENVIRONMENT_NAME_LENGTH
// ENVIRONMENT_VARIANT

// PLATFORM
// PLATFORM_NAME
// PLATFORM_NAME_LENGTH
// PLATFORM_NAME_LENGTH_MAX
// PLATFORM_VARIANT

/* platforms */
#define WINDOWS         1
#define LINUX           2
#define UNIX            3
#define MACINTOSH       4
#define BSD_ENVIRONMENT 5
#define ANDROID         6
#define GNU             7
#define CYGWIN          8
#define EMX             9
#define INTERIX        10
#define WINDU          11

/* platform variants */
/* WINDOWS */
#define WINDOWS_CE              12
#define WINDOWS_HPC2000         13
#define WINDOWS_HPCPRO          14
#define WINDOWS_POCKETPC        15
#define WINDOWS_MOBILE_2003     16
#define WINDOWS_SMARTPHONE_2002 17
/* LINUX */
#define SOLARIS 18
#define GNULINUX 19
#define MINIX 20
/* UNIX */
#define DRAGONFLY   21
#define HPUX        22
#define UNIXWARE    23
#define LYNX        24
#define DGUX_SYSTEM 25
#define SINUX       26
#define ULTRIX      27
#define DYNIX       28


/* other platforms */
#define AIX            29
#define OS400          30
#define FREEBSD        31
#define NETBSD         32
#define OPENBSD        33
#define BSDI           34
#define KFREEBSD       35
#define OS9            36
#define BEOS           37
#define AMIGAOS        38
#define MORPH          39
#define AEGIS          40
#define BLUE_GENE      41
#define AMDAHL_UTS     42
#define CONVEX         43
#define ECOS           44
#define HIUXMPP        45
#define INTEGRITY      46
#define MPE            47
#define MSDOS_SYSTEM   48
#define NONSTOP        49
#define NUCLEUS        50
#define OS2_SYSTEM     51
#define PALMOS         52
#define ZOS            53
#define PLAN9          54
#define PYRAMIDDC      55
#define QNX            56
#define SCO_OPENSERVER 57
#define STRATUS_VOS    58
#define SVR4           59
#define SYLLABLE       60
#define SYMBIAN        61
#define TRU64          62
#define UNICOS         63
#define VMS_SYSTEM     64
#define VXWORKS        65

#define UNKNOWN 66

// based on 0.1% percentile of word length distribution for English (16 * 4 = 64 characters)
// source: <http://www.ravi.io/language-word-lengths>
#define PLATFORM_NAME_LENGTH_MAX 64


/******************************************PLATFORMS******************************************/


/* Windows */

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#define PLATFORM WINDOWS
#define PLATFORM_VARIANT WINDOWS
#define PLATFORM_NAME "Windows"
#define PLATFORM_NAME_LENGTH 8
#endif

#if defined(_WIN32_WCE)
	#define PLATFORM WINDOWS
	#define PLATFORM_VARIANT WINDOWS_CE
	#define PLATFORM_NAME "Windows CE"
	#define PLATFORM_NAME_LENGTH 11
#endif

#if defined(WIN32_PLATFORM_HPC2000)
	#define PLATFORM WINDOWS
	#define PLATFORM_VARIANT WINDOWS_HPC2000
	#define PLATFORM_NAME "Windows HPC 2000"
	#define PLATFORM_NAME_LENGTH 17
#endif

#if defined(WIN32_PLATFORM_HPCPRO)
	#define PLATFORM WINDOWS
	#define PLATFORM_VARIANT WINDOWS_HPCPRO
	#define PLATFORM_NAME "Windows HPC Pro"
	#define PLATFORM_NAME_LENGTH 16
#endif

#if defined(WIN32_PLATFORM_PSPC)
	#define PLATFORM WINDOWS
	#if WIN32_PLATFORM_PSPC < 400
		#define PLATFORM_VARIANT WINDOWS_POCKETPC
		#define PLATFORM_NAME "Windows PocketPC"
		#define PLATFORM_NAME_LENGTH 17
	#else
		#define PLATFORM_VARIANT WINDOWS_MOBILE_2003
		#define PLATFORM_NAME "Windows Mobile 2003"
		#define PLATFORM_NAME_LENGTH 20
	#endif
#endif

#if defined(WIN32_PLATFORM_WFSP)
	#define PLATFORM WINDOWS
	#define PLATFORM_VARIANT WINDOWS_SMARTPHONE_2002
	#define PLATFORM_NAME "Windows Smartphone 2002"
	#define PLATFORM_NAME_LENGTH 24
#endif

/* LINUX */

#if defined(__linux__) || defined(linux) || defined(__linux)
	#define ENVIRONMENT UNIX
	#define PLATFORM LINUX
	#define PLATFORM_VARIANT LINUX
	#define PLATFORM_NAME "Linux"
	#define PLATFORM_NAME_LENGTH 6
#endif

#if defined(__gnu_linux__)
	#define ENVIRONMENT UNIX
	#define PLATFORM LINUX
	#define PLATFORM_VARIANT GNULINUX
	#define PLATFORM_NAME "GNU Linux"
	#define PLATFORM_NAME_LENGTH 10
#endif

#if defined(__minix)
	#define ENVIRONMENT UNIX
	#define PLATFORM LINUX
	#define PLATFORM_VARIANT MINIX
	#define PLATFORM_NAME "Minix"
	#define PLATFORM_NAME_LENGTH 6
#endif

/* UNIX */

#if defined(__unix__) || defined(__unix)
	#if !CYGWIN
		#define PLATFORM UNIX
		#define PLATFORM_VARIANT UNIX
		#ifndef PLATFORM_NAME
			#define PLATFORM_NAME "Unix"
			#define PLATFORM_NAME_LENGTH 5
		#endif
	#endif
#endif

/* UNIX-derivative (newest to oldest release descending) */

/* DragonFly */
#if defined(__DragonFly__)
	#define PLATFORM UNIX
	#define PLATFORM_VARIANT DRAGONFLY
	#define PLATFORM_NAME "DragonFly"
	#define PLATFORM_NAME_LENGTH 10
#endif

/* HPUX */
#if defined(_hpux) || defined(hpux) || defined(__hpux)
	#define PLATFORM UNIX
	#define PLATFORM_VARIANT HPUX
	#define PLATFORM_NAME "HP-UX"
	#define PLATFORN_NAME_LENGTH 6
#endif

/* UnixWare */
#if defined(sco) || defined(_UNIXWARE7)
	#define PLATFORM UNIX
	#define PLATFORM_VARIANT UNIXWARE
	#define PLATFORM_NAME "UnixWare"
	#define PLATFORM_NAME_LENGTH 9
#endif

/* LynxOS */
#if defined(__Lynx__)
	#define PLATFORM UNIX
	#define PLATFORM_VARIANT LYNX
	#define PLATFORM_NAME "Lynx"
	#define PLATFORM_NAME_LENGTH 5
#endif

/* DG/UX */
#if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
	#define PLATFORM UNIX
	#define PLATFORM_VARIANT DGUX_SYSTEM
	#define PLATFORM_NAME "DG/UX"
	#define PLATFORM_NAME_LENGTH 6
#endif

/* Reliant UNIX */
#if defined(sinux)
	#define PLATFORM UNIX
	#define PLATFORM_VARIANT SINUX
	#define PLATFORM_NAME "Reliant UNIX"
	#define PLATFORM_NAME_LENGTH 13
#endif

/* Ultrix */
#if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || (defined(unix) && defined(vax))
	#define PLATFORM UNIX
	#define PLATFORM_VARIANT ULTRIX
	#define PLATFORM_NAME "Ultrix"
	#define PLATFORM_NAME_LENGTH 7
#endif

/* DYNIX */
#if defined(_SEQUENT_) || defined(sequent)
	#define PLATFORM UNIX
	#define PLATFORM_VARIANT DYNIX
	#define PLATFORM_NAME "DYNIX/ptx"
	#define PLATFORM_NAME_LENGTH 10
#endif

/* AIX */

#if defined(_AIX) || defined(__TOS_AIX__)
	#define PLATFORM AIX
	#define PLATFORM_VARIANT AIX
	#define PLATFORM_NAME "AIX"
	#define PLATFORM_NAME_LENGTH 4
#endif

/* APPLE MACINTOSH/MAC OS X */

#if defined(macintosh) || defined(Macintosh)
	#define PLATFORM MACINTOSH
	#define PLATFORM_VARIANT MACINTOSH
	#define PLATFORM_NAME "Macintosh"
	#define PLATFORM_NAME_LENGTH 10
#endif

#if defined(__APPLE__) && defined(__MACH__)
	#define PLATFORM MACINTOSH
	#define PLATFORM_VARIANT MACOSX
	#define PLATFORM_NAME "Mac OS/X"
	#define PLATFORM_NAME_LENGTH 9
#endif

/* IBM OS/400 */

#if defined(__OS400__)
	#define PLATFORM OS400
	#define PLATFORM_VARIANT OS400
	#define PLATFORM_NAME "IBM OS/400"
	#define PLATFORM_NAME_LENGTH 11
#endif

/* BSD */

#if defined(__FreeBSD__)
	#define PLATFORM BSD_ENVRIONMENT
	#define PLATFORM_VARIANT FREEBSD
	#define PLATFORM_NAME "FreeBSD"
	#define PLATFORM_NAME_LENGTH 8
#endif

#if defined(__NetBSD__)
	#define PLATFORM BSD_ENVIRONMENT
	#define PLATFORM_VARIANT NETBSD
	#define PLATFORM_NAME "NetBSD"
	#define PLATFORM_NAME_LENGTH 7
#endif

#if defined(__OpenBSD__)
	#define PLATFORM BSD_ENVIRONMENT
	#define PLATFORM_VARIANT OPENBSD
	#define PLATFORM_NAME "OpenBSD"
	#define PLATFORM_NAME_LENGTH 8
#endif

#if defined(__bsdi__)
	#define PLATFORM BSD_ENVIRONMENT
	#define PLATFORM_VARIANT BSDI
	#define PLATFORM_NAME "BSDi"
	#define PLATFORM_NAME_LENGTH 5
#endif

#if defined(BSD)
	#define PLATFORM BSD_ENVIRONMENT
	#define PLATFORM_NAME "BSD"
	#define PLATFORM_NAME_LENGTH 4
#endif

#if defined(_SYSTYPE_BSD)
	#define PLATFORM BSD_ENVIRONMENT
	#define PLATFORM_VARIANT BSD
	#define PLATFORM_NAME "BSD"
	#define PLATFORM_NAME_LENGTH 4
#endif

#if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
	#define PLATFORM BSD_ENVIRONMENT
	#define PLATFORM_VARIANT KFREEBSD
	#define PLATFORM_NAME "KFreeBSD"
	#define PLATFORM_NAME_LENGTH 9
#endif

/* Android */

#if defined(__ANDROID__)
	#define PLATFORM ANDROID
	#define PLATFORM_VARIANT ANDROID
	#define PLATFORM_NAME "Android"
	#define PLATFORM_NAME_LENGTH 8
#endif

/* Solaris */

#if defined(sun) || defined(__sun)
	#define ENVIRONMENT UNIX
	#define PLATFORM LINUX
	#define PLATFORM_VARIANT SOLARIS
	#define PLATFORM_NAME "Oracle Solaris"
	#define PLATFORM_NAME_LENGTH 15
#endif

/* GNU */

#if defined(__GNU__) || defined(__gnu_hurd__)
	#define PLATFORM GNU
	#define PLATFORM_VARIANT GNU
	#define PLATFORM_NAME "GNU"
	#define PLATFORM_NAME_LENGTH 4
#endif

/* OS-9 */

#if defined(__OS9000) || defined(_OSK)
	#define PLATFORM OS9
	#define PLATFORM_VARIANT OS9
	#define PLATFORM_NAME "Microware OS-9"
	#define PLATFORM_NAME_LENGTH 15
#endif

/* BeOS  */

#if defined(__BEOS__)
	#define PLATFORM BEOS
	#define PLATFORM_VARIANT BEOS
	#define PLATFORM_NAME "BeOS"
	#define PLATFORM_NAME_LENGTH 5
#endif

/* AmigaOS */

#if defined(AMIGA) || defined(__amigaos__)
	#define PLATFORM AMIGAOS
	#define PLATFORM_VARIANT AMIGAOS
	#define PLATFORM_NAME "AmigaOS"
	#define PLATFORM_NAME_LENGTH 8
#endif

/* MorphOS */

#if defined(__MORPHOS__)
	#define PLATFORM MORPH
	#define PLATFORM_VARIANT MORPH
	#define PLATFORM_NAME "MorphOS"
	#define PLATFORM_NAME_LENGTH 8
#endif

/* Aegis */

#if defined(aegis)
	#define PLATFORM AEGIS
	#define PLATFORM_VARIANT AEGIS
	#define PLATFORM_NAME "Apollo AEGIS"
	#define PLATFORM_NAME_LENGTH 13
#endif

/* Blue Gene */

#if defined(__bg__) || defined(__THW_BLUEGENE__)
	#define PLATFORM BLUE_GENE
	#define PLATFORM_VARIANT BLUE_GENE
	#define PLATFORM_NAME "Blue Gene"
	#define PLATFORM_NAME_LENGTH 10
#endif

/* Amdahl UTS */

#if defined(UTS)
	#define PLATFORM UTS
	#define PLATFORM_VARIANT AMDAHL_UTS
	#define PLATFORM_NAME "Amdahl UTS"
	#define PLATFORM_NAME_LENGTH 11
#endif

/* Convex */

#if defined(__convex__)
	#define PLATFORM CONVEX
	#define PLATFORM_VARIANT CONVEX
	#define PLATFORM_NAME "ConvexOS"
	#define PLATFORM_NAME_LENGTH 9
#endif

/* eCos */

#if defined(__ECOS)
	#define PLATFORM ECOS
	#define PLATFORM_VARIANT ECOS
	#define PLATFORM_NAME "eCos"
	#define PLATFORM_NAME_LENGTH 5
#endif

/* OSF/1 AD */

#if defined(__hiuxmpp)
	#define PLATFORM HIUXMPP
	#define PLATFORM_VARIANT HIUXMPP
	#define PLATFORM_NAME "HI-UX MPP"
	#define PLATFORM_NAME_LENGTH 10
#endif

/* INTEGRITY */

#if defined(__INTEGRITY)
	#define PLATFORM INTEGRITY
	#define PLATFORM_VARIANT INTEGRITY
	#define PLATFORM_NAME "INTEGRITY"
	#define PLATFORM_NAME_LENGTH 10
#endif

/* MPE */

#if defined(mpeix) || defined(__mpexl)
	#define PLATFORM MPE
	#define PLATFORM_VARIANT MPE
	#define PLATFORM_NAME "MPE/iX"
	#define PLATFORM_NAME_LENGTH 7
#endif

/* MSDOS */

#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
	#define PLATFORM MSDOS_SYSTEM
	#define PLATFORM_VARIANT MSDOS_SYSTEM
	#define PLATFORM_NAME "MSDOS"
	#define PLATFORM_NAME_LENGTH 6
#endif

/* NonStop */

#if defined(__TANDEM)
	#define PLATFORM NONSTOP
	#define PLATFORM_VARIANT NONSTOP
	#define PLATFORM_NAME "NonStop"
	#define PLATFORM_NAME_LENGTH 8
#endif

/* Nucleus RTOS */

#if defined(__nucleus__)
	#define PLATFORM NUCLEUS
	#define PLATFORM_VARIANT NUCLEUS
	#define PLATFORM_NAME "Nucleus RTOS"
	#define PLATFORM_NAME_LENGTH 13
#endif

/* OS/2 */

#if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
	#define PLATFORM OS2_SYSTEM
	#define PLATFORM_VARIANT OS2_SYSTEM
	#define PLATFORM_NAME "OS/2"
	#define PLATFORM_NAME_LENGTH 5
#endif

/* PalmOS */

#if defined(__palmos__)
	#define PLATFORM PALMOS
	#define PLATFORM_VARIANT PALMOS
	#define PLATFORM_NAME "PalmOS"
	#define PLATFORM_NAME_LENGTH 7
#endif

/* z/OS */

#if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
	#define PLATFORM ZOS
	#define PLATFORM_VARIANT ZOS
	#define PLATFORM_NAME "z/OS"
	#define PLATFORM_NAME_LENGTH 5
#endif

/* Plan 9 */

#if defined(EPLAN9)
	#define PLATFORM PLAN9
	#define PLATFORM_VARIANT PLAN9
	#define PLATFORM_NAME "Plan 9"
	#define PLATFORM_NAME_LENGTH 7
#endif

/* Pyramid DC/OSx */

#if defined(pyr)
	#define PLATFORM PYRAMIDDC
	#define PLATFORM_VARIANT PYRAMIDDC
	#define PLATFORM_NAME "Pyramid DC/OSx"
	#define PLATFORM_NAME_LENGTH 15
#endif

/* QNX */

#if defined(__QNX__) || defined(__QNXNTO__)
	#define PLATFORM QNX
	#define PLATFORM_VARIANT QNX
	#define PLATFORM_NAME "QNX"
	#define PLATFORM_NAME_LENGTH 4
#endif
/* SCO OpenServer */

#if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
	#define PLATFORM SCO_OPENSERVER
	#define PLATFORM_VARIANT SCO_OPENSERVER
	#define PLATFORM_NAME "SCO OpenServer"
	#define PLATFORM_NAME_LENGTH 15
#endif

/* Stratus VOS */

#if defined(__VOS__)
	#define PLATFORM STRATUS_VOS
	#define PLATFORM_VARIANT STRATUS_VOS
	#define PLATFORM_NAME "Stratus VOS"
	#define PLATFORM_NAME_LENGTH 12
#endif

/* SVR4 */

#if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
	#define PLATFORM SVR4
	#define PLATFORM_VARIANT SVR4
	#define PLATFORM_NAME "SVR4"
	#define PLATFORM_NAME_LENGTH 5
#endif

/* Syllable */

#if defined(__SYLLABLE__)
	#define PLATFORM SYLLABLE
	#define PLATFORM_VARIANT SYLLABLE
	#define PLATFORM_NAME "Syllable"
	#define PLATFORM_NAME_LENGTH 9
#endif

/* Symbian OS */

#if defined(__SYMBIAN32__)
	#define PLATFORM SYMBIAN
	#define PLATFORM_VARIANT SYMBIAN
	#define PLATFORM_NAME "Symbian OS"
	#define PLATFORM_NAME_LENGTH 11
#endif

/* Tru64 (OSF/1) */

#if defined(__osf__) || defined(__osf)
	#define PLATFORM TRU64
	#define PLATFORM_VARIANT TRU64
	#define PLATFORM_NAME "Tru64 (OSF/1)"
	#define PLATFORM_NAME_LENGTH 14
#endif

/* UNICOS */

#if defined(_UNICOS)
	#define PLATFORM UNICOS
	#define PLATFORM_VARIANT UNICOS
	#define PLATFORM_NAME "UNICOS"
	#define PLATFORM_NAME_LENGTH 7
#endif

/* VMS */

#if defined(VMS) || defined(__VMS)
	#define PLATFORM VMS_SYSTEM
	#define PLATFORM_VARIANT VMS_SYSTEM
	#define PLATFORM_NAME "VMS"
	#define PLATFORM_NAME_LENGTH 4
#endif

/* VxWorks */

#if defined(__VXWORKS__) || defined(__vxworks)
	#define PLATFORM VXWORKS
	#define PLATFORM_VARIANT VXWORKS
	#define PLATFORM_NAME "VxWorks"
	#define PLATFORM_NAME_LENGTH 8
#endif


/******************************************ENVIRONMENTS******************************************/


/* Cygwin */

#if defined(__CYGWIN__)
	#define ENVIRONMENT CYGWIN
	#ifndef PLATFORM
		#define PLATFORM WINDOWS
		#define PLATFORM_NAME "Windows"
		#define PLATFORM_NAME_LENGTH 8
	#endif
#endif

/* EMX */

#if defined(__EMX__)
	#define ENVIRONMENT EMX
#endif

/* Interix */

#if defined(__INTERIX)
	#define ENVIRONMENT INTERIX
#endif

/* Wind/U */

#if defined(_WINDU_SOURCE)
	#define ENVIRONMENT WINDU
	#define PLATFORM WINDU
	#define PLATFORM_VARIANT WINDU
#endif


// fail-safes
#ifndef PLATFORM
	#ifdef PLATFORM_VARIANT
		#define PLATFORM PLATFORM_VARIANT
	#else
		#define PLATFORM UKNOWN
	#endif
#endif

#ifndef ENVIRONMENT
	#define ENVIRONMENT PLATFORM
#endif

/* generic platform functions */

#include "../debug.h"
#include <stdint.h>

struct p_result {
	union {
		void *value;

		void (*function)();
	} content;

	enum result_code code;
};

enum device_type {
	PHYSICAL,
	LOGICAL
};

struct p_device {
	// the unique identifier for this device
	uintmax_t id;
	// the device name string
	char *name;
	// the platform-dependent interface module name of this device, commonly called the device driver
	// may otherwise be a logical interface, a.k.a. virtual device driver.
	// To be used with p_get_fn's module parameter
	char *interface_module;
	enum device_type type;
};

/*
 * # `struct p_result p_get_platform();`
 * Gets the platform (friendly) name string. Use the macro expansion `PLATFORM_NAME_LENGTH` for string length (with null terminator).
 *
 * You may alternatively use the `PLATFORM_NAME` macro when you do not need to retrieve the friendly platform name strictly
 * at runtime.
 *
 * ## `return struct p_result`
 * A `struct p_result` containing a pointer of type `char *`, a null-terminated string containing the platform name.
 */
struct p_result p_get_platform();

struct p_result p_get_env(char *var);

/* platform functional programming */

/*
 * # `struct p_result p_get_fn(char *module, char *function);` ("get function")
 * Gets a function from the specified implementation-specific module. The module is explicitly the name of the module
*  without any sort of file extension, and will first check the program's environment for an existing module before
*  searching the system's environment for the given module. If the function succeeds in finding the module, the function
*  will attempt to retrieve the address of the specified function, or return NULL with result code R_INITIALIZATION_FAILURE.
*
*  If the function is unable to find the module name, the result will contain a NULL result with result code R_FAILURE.
 *
 *  ## `char *module`
 *  a string containing the module name
 *
 *  ## `char *function`
 *  a string containing the function name
*/
struct p_result p_get_fn(char *module, char *function);

/*
 * # `struct p_result p_get_fna(char *module, uintptr_t function_offset);` ("get function absolute")
 * Gets a function from the specified function offset which is an absolute address relative to the offset within a program
 * or shared library.
 *
 * ## `char *module`
 * a string containing the module name
 *
 * ## `uintptr_t function_offset`
 * a pointer value representing the offset of the function relative to the start of the module
 */
struct p_result p_get_fna(char *module, uintptr_t function_offset);

/* platform hardware enumeration */

struct p_device p_get_device();

#endif /* INCLUDE_PLATFORM_H_ */