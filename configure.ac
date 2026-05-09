# Initialize Autoconf
AC_PREREQ([2.69])
AC_INIT([mtd], [1.0], [hastagaming@github.com])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MKDIR_P

# Checks for libraries (if any)

# Checks for header files
AC_CHECK_HEADERS([stdlib.h string.h unistd.h dirent.h sys/stat.h])

# Checks for typedefs, structures, and compiler characteristics
AC_TYPE_SIZE_T
AC_CHECK_TYPES([struct stat])

# Checks for library functions
AC_FUNC_MALLOC
AC_CHECK_FUNCS([mkdir rmdir rename strrchr strstr])

# Output files
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
