/*
 * file:     msl_c_lib.c
 * unit:     yes
 * function: MSL_C_LIB_EmptyStub, MSL_C_LIB_TwlCall1, MSL_C_LIB_TwlCall3, MSL_C_LIB_TwlCall2, MSL_C_LIB_TwlCall5, MSL_C_LIB_SetTwlFlag, MSL_C_LIB_LockRegisterDestructor, nan, MSL_C_LIB_AllocAllFromHeap, MSL_C_LIB_FreeToHeap, MSL_C_LIB_PrependResourceSet, MSL_C_LIB_AllocFromHeap, func_020913E8, MSL_C_LIB_ReallocResource, MSL_C_LIB_Calloc, MSL_C_LIB_FlushAllGated, MSL_C_LIB_FlushAll, abs, MSL_C_LIB_NopBufferHookA, MSL_C_LIB_NopBufferHookB, __prep_buffer, __load_buffer, __flush_buffer, fread, __fread, fclose, MSL_C_LIB_FlushStream, func_02091C40, __ftell, ftell, __fseek, fseek, rewind, MSL_C_LIB_PopCount64, __signbitd, __fpclassifyd, MSL_C_LIB_MbrToWc, MSL_C_LIB_WcToMb, MSL_C_LIB_CallFormatHook, MSL_C_LIB_WideToNarrow, func_02092344, memmove, MSL_C_LIB_MemsetPtr, memchr, func_020923F0, func_02092430, parse_format, long2str, longlong2str, double2hex, round_decimal, float2str, __pformatter, MSL_C_LIB_SprintfWriteProc, vsnprintf, sprintf, qsort, func_02094694, srand, MSL_C_LIB_StrReadProc, MSL_C_LIB_CallExitHook, MSL_C_LIB_DefaultExitHook, strlen, strcpy, strncpy, strcat, strcmp, strncmp, strchr, strcspn, strstr, __strtold, strtod, atof, __strtoul, strtoul, strtol, __strtoull, strtoll, atoi, atoll, fwide, wcslen, wcscpy, func_020965B4, MSL_C_LIB_IncrementDigits, MSL_C_LIB_SetPrecision, __ull2dec, __timesdec, __str2dec, __two_exp, __equals_dec, __less_dec, __minus_dec, __num2dec, __dtoa, __dec2num, scalbn, __ieee754_pow, __ieee754_rem_pio2, __kernel_cos
 * address:  0x020911D4
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SNDEXi_Init  0x02704364  arm
 *   SHA1_HMAC_Init  0x02731754  thumb
 *   SHA1_HMAC_Update  0x02731760  thumb
 *   SHA1_HMAC_GetHash  0x02731764  thumb
 *   SHA1_HMAC_Calc  0x02731920  arm
 *   OSi_IsRunOnTwl    0x02085D88  arm
 *   OS_Terminate    0x02088234  arm
 *   gMslTwlFlag  0x02153B88  data
 *   OS_LockMutex  0x02086028  arm
 *   OS_TryLockMutex  0x020860D0  arm
 *   func_02086078  0x02086078  arm
 *   MSL_CONSOLE_IO_RegisterDestructor  0x0209D728  arm
 *   gMslRefToken  0x02150FEC  data
 *   g_02153B8C  0x02153B8C  data
 *   g_02153BB0  0x02153BB0  data
 *   gMslMutexTable  0x02153BD4  data
 *   g_020A8818  0x020A8818  data
 *   func_0209BD38  0x0209BD38  arm
 *   OS_AllocFromHeap  0x020868E0  arm
 *   OS_FreeToHeap  0x020869E8  arm
 *   ENV_InsertResourceSet  0x02086C54  arm
 *   gMslStream0  0x020A8730  data
 *   gMslRefGen  0x02153B8C  data
 *   gMslRefCount  0x02153BB0  data
 *   func_0209C2B0  0x0209C2B0  arm
 *   __tolower_map  0x020A60DC  data
 *   errno  0x02153FAC  data
 *   gMslStream1  0x020A877C  data
 *   gMslStream2  0x020A87C8  data
 *   gMslFormatHook  0x020A8878  data
 *   _u32_div_f  0x0209C2B0  arm
 *   _ll_udiv  0x0209C00C  arm
 *   _ull_mod  0x0209C018  arm
 *   fabs  0x0209A504  arm
 *   _dneq  0x0209BAC8  arm
 *   _dls  0x0209B9A0  arm
 *   MslRandSeed  0x020A8A78  data
 *   gMslExitHook  0x02153FB0  data
 *   __float_huge  0x020A8814  data
 *   _fsub  0x0209CB8C  arm
 *   _f2d  0x0209BD38  arm
 *   _dsub  0x0209AF34  arm
 *   _dgr  0x0209B864  arm
 *   FATFSi_FormatDriveEx  0x02095AA4  arm
 *   _deq  0x0209BA3C  arm
 *   func_0209AF34  0x0209AF34  arm
 *   frexp  0x0209A6E8  arm
 *   ldexp  0x0209A7A8  arm
 *   func_0209C554  0x0209C554  arm
 *   copysign  0x0209A368  arm
 *   pow  0x0209AB80  arm
 *   _dfltu  0x0209B790  arm
 *   _dmul  0x0209B2E8  arm
 *   _dadd  0x0209AC04  arm
 *   _dflt  0x0209B750  arm
 *   _ddiv  0x0209D1E0  arm
 *   pow_10  0x020A8A7C  data
 *   __ctype_map  0x020A61DC  data  a2
 *   sMslNegInf     0x020A8A40  data  a1
 *   sMslNegInfLower     0x020A8A48  data  a1
 *   sMslPosInf     0x020A8A50  data  a1
 *   sMslPosInfLower     0x020A8A54  data  a1
 *   sMslNegNan     0x020A8A58  data  a1
 *   sMslNegNanLower     0x020A8A60  data  a1
 *   sMslPosNan     0x020A8A68  data  a1
 *   sMslPosNanLower     0x020A8A6C  data  a1
 *   sMslWideEmpty     0x020A8A70  data  a2
 *   sMslNarrowEmpty     0x020A8A74  data  a1
 *   s_infinity     0x020A62E4  data  a1
 *   s_nan          0x020A62DC  data  a1
 *   __upper_map    0x020A615C  data  a1
 *   __double_huge  0x020A881C  data  a4
 *   s_020A8ABC     0x020A8ABC  data  a1
 *   s_020A8AEC     0x020A8AEC  data  a1
 *   s_020A8B14     0x020A8B14  data  a1
 *   s_020A8B2C     0x020A8B2C  data  a1
 *   s_020A8B3C     0x020A8B3C  data  a1
 *   s_020A8B44     0x020A8B44  data  a1
 *   s_020A8B4C     0x020A8B4C  data  a1
 *   s_020A8B54     0x020A8B54  data  a1
 *   s_020A8B5C     0x020A8B5C  data  a1
 *   s_020A8B60     0x020A8B60  data  a1
 *   s_020A8B64     0x020A8B64  data  a1
 *   s_020A8B68     0x020A8B68  data  a1
 *   s_020A8B6C     0x020A8B6C  data  a1
 *   s_020A8B70     0x020A8B70  data  a1
 *   s_020A8B74     0x020A8B74  data  a1
 *   s_020A8B78     0x020A8B78  data  a1
 *   s_020A8B7C     0x020A8B7C  data  a1
 *   s_020A8B80     0x020A8B80  data  a1
 *   s_020A8B84     0x020A8B84  data  a1
 *   s_020A8B88     0x020A8B88  data  a1
 *   s_020A8B8C     0x020A8B8C  data  a1
 *   s_020A8B90     0x020A8B90  data  a1
 *   _dleq  0x0209B8FC  arm
 *   func_0209C5E0  0x0209C5E0  arm
 *   scalbn  0x02097990  arm
 *   bp  0x020A6300  data
 *   dp_h  0x020A62F0  data
 *   dp_l  0x020A6310  data
 *   __float_nan  0x020A8818  data
 *   errno  0x02153FAC  data
 *   _dfix  0x0209C508  arm
 *   __kernel_rem_pio2  0x0209953C  arm
 *   npio2_hw  0x020A6320  data
 *   two_over_pi  0x020A63A0  data
 */

#define __va_size(t) ((sizeof(t) + 3) & ~3)
#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))
#define table_ptr(i) (((char *)table_base) + (member_size * ((i) - 1)))
#define swap(dst, src, cnt)                          \
    do {                                             \
        size_t n = (cnt);                            \
        unsigned char *p = (unsigned char *)(src);   \
        unsigned char *q = (unsigned char *)(dst);   \
        if (n) do {                                  \
            unsigned char a = *p;                    \
            unsigned char b = *q;                    \
            *q++ = a;                                \
            *p++ = b;                                \
        } while (--n);                               \
    } while (0)
#define K1 0xFEFEFEFF
#define K2 0x80808080
#define isalpha(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x1))
#define isspace(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x100))
#define isxdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x400))
#define toupper(c)  (((c) < 0 || (c) >= 0x80) ? (c) : __upper_map[c])
#define INFINITY __float_huge
#define HUGE_VAL __double_huge
#define hex_success(count, s) ((count) - 1 > 2 && ((s) & (hex_leading_sig_zeroes | \
                           hex_int_digit_loop | hex_frac_digit_loop | \
                           hex_leading_exp_zeroes | hex_exp_digit_loop)))
#define fetch()    (count++, (*ReadProc)(ReadProcArg, 0, 0))
#define unfetch(c) (*ReadProc)(ReadProcArg, c, 1)
#define FP_INFINITE 2
#define isinf(x) (__fpclassifyd(x) == FP_INFINITE)
#define HI(x) (((i32 *)&(x))[1])
#define LO(x) (((i32 *)&(x))[0])
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   size_t;

typedef unsigned short wchar_t;

typedef unsigned long long u64;

typedef unsigned char uchar;

typedef signed short   s16;

typedef long long s64;

typedef long ptrdiff_t;

typedef long long intmax_t;

struct FILE;

typedef struct {
    u32 open_mode        : 2;
    u32 io_mode          : 3;
    u32 buffer_mode      : 2;
    u32 file_kind        : 3;
    u32 file_orientation : 2;
    u32 binary_io        : 1;
} file_modes;

typedef struct {
    u32 io_state    : 3;
    u32 free_buffer : 1;
} file_state;

typedef struct FILE {
    u32        handle;              /* 0x00 */
    file_modes mode;                /* 0x04 */
    file_state state;               /* 0x08 */
    u8         eof;                 /* 0x0c */
    u8         error;               /* 0x0d */
    u8         char_buffer;         /* 0x0e */
    u8         char_buffer_overflow;/* 0x0f */
    u8         pad10[2];            /* 0x10 */
    u8         ungetc_buffer[2];    /* 0x12 */
    wchar_t    ungetwc_buffer[2];   /* 0x14 */
    u32        position;            /* 0x18 */
    u8        *buffer;              /* 0x1c */
    u32        buffer_size;         /* 0x20 */
    u8        *buffer_ptr;          /* 0x24 */
    u32        buffer_len;          /* 0x28 */
    u32        buffer_alignment;    /* 0x2c */
    u32        saved_buffer_len;    /* 0x30 */
} FILE;

struct MslRefBlock {
    u32 reserved00;
    u32 *refs;
};

typedef struct MslStream {
    u32 handle;             /* 0x00 */
    u32 mode;               /* 0x04 */
    u32 state;              /* 0x08 */
    u8  eof;                /* 0x0c */
    u8  error;              /* 0x0d */
    u8  pad0e[0x0a];
    u32 position;           /* 0x18 */
    u32 buffer;             /* 0x1c */
    u32 buffer_size;        /* 0x20 */
    u32 buffer_ptr;         /* 0x24 */
    u32 buffer_len;         /* 0x28 */
    u32 buffer_alignment;   /* 0x2c */
    u32 pad30;              /* 0x30 */
    u32 saved_buffer_len;   /* 0x34 */
    u32 (*seek_proc)(u32, u32 *, u32, u32);  /* 0x38 */
    u32 read_proc;          /* 0x3c */
    u32 write_proc;         /* 0x40 */
    u32 close_proc;         /* 0x44 */
    u32 ref_con;            /* 0x48 */
} MslStream;

struct MslFileKind {
    u32 pad  : 7;
    u32 kind : 3;
    u32 rest : 22;
};

struct MslFileIoBits {
    u32 pad     : 2;
    u32 io_mode : 3;
    u32 rest    : 27;
};

struct MslFileModeBits {
    u32 pad         : 2;
    u32 io_mode     : 3;
    u32 buffer_mode : 2;
    u32 kind        : 3;
    u32 rest        : 22;
};

struct MslStateBits {
    u32 mode : 3;
    u32 rest : 29;
};

typedef struct {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    u32 w5;
    u32 w6;
    u32 w7;
} MslMemsetBlock;

typedef struct {
    u8 *buf;
    u32 capacity;
    u32 length;
} MslStringBuf;

typedef u32 (*MslReadFn)(u32, u32, u32 *, u32);
typedef u32 (*MslWriteFn)(u32, u32, u32 *, u32);

typedef struct {
    unsigned char pad[4];
    u32 (*proc)(u32 *dst, u32 c);
} MslFormatHook;

typedef struct {
    unsigned char pad[8];
    MslFormatHook *hook;
} MslFormatHookHolder;

typedef uchar *va_list;

typedef struct {
    unsigned char justification_options;
    unsigned char sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} print_format;

typedef struct { char style; short digits; } decform;

typedef struct {
    unsigned char sgn;
    char unused;
    short exp;
    struct { unsigned char length; unsigned char text[34]; unsigned char unused; } sig;
} decimal;

typedef struct {
    u16 reserved0;
    s16 exp;
    u8  length;
    u8  digits[1];
} Ctr;

typedef struct { char c[5]; } Str5;

typedef struct { char c[4]; } Str4;

typedef int (*_compare_function)(const void *, const void *);

typedef void (*MslExitHook)(u32, u32, u32);

typedef struct decimal2 {
    unsigned char sign;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal2;

typedef struct { unsigned char c[9]; } model9;

typedef struct { unsigned char c[5]; } model5;

enum scan_states {
    start              = 0x0001,
    sig_start          = 0x0002,
    leading_sig_zeroes = 0x0004,
    int_digit_loop     = 0x0008,
    frac_start         = 0x0010,
    frac_digit_loop    = 0x0020,
    sig_end            = 0x0040,
    exp_start          = 0x0080,
    leading_exp_digit  = 0x0100,
    leading_exp_zeroes = 0x0200,
    exp_digit_loop     = 0x0400,
    finished           = 0x0800,
    failure            = 0x1000,
    nan_state          = 0x2000,
    infin_state        = 0x4000,
    hex_state          = 0x8000
};

enum hex_scan_states {
    not_hex                = 0x0000,
    hex_start              = 0x0001,
    hex_leading_sig_zeroes = 0x0002,
    hex_int_digit_loop     = 0x0004,
    hex_frac_digit_loop    = 0x0008,
    hex_sig_end            = 0x0010,
    hex_exp_start          = 0x0020,
    hex_leading_exp_digit  = 0x0040,
    hex_leading_exp_zeroes = 0x0080,
    hex_exp_digit_loop     = 0x0100
};

struct MslDecString {
    u8  sign;
    u8  pad01;
    u16 exp;
    u8  length;
    u8  digits[32];
};

typedef struct {
    u8  reserved00[2];
    s16 key;
    volatile u8 length;
    u8  data[];
} MslStrRec;

typedef void (*DecFromStr)(decimal2 *d, const char *s, s16 exp);

typedef struct DB {
    u8  sign;
    u8  pad;
    s16 exp;
    u8  length;
    u8  digits[33];
} DB;

/* Matched units compiled in this file, entered 4 bytes before their function:
 * unit_020979BC (0x020979BC) holds __ieee754_pow
 * unit_02098B44 (0x02098B44) holds __ieee754_rem_pio2
 * unit_02099224 (0x02099224) holds __kernel_cos
 */
typedef int i32;

extern int OSi_IsRunOnTwl(void);
extern void OS_Terminate(void);
extern void OS_LockMutex(void *mutex);
extern int OS_TryLockMutex(void *mutex);
extern void func_02086078(void *mutex);
extern int MSL_CONSOLE_IO_RegisterDestructor(int a);
extern double func_0209BD38(int x);
extern void *OS_AllocFromHeap(u32 a, u32 b, u32 heap);
extern void OS_FreeToHeap(u32 a, u32 b, u32 heap);
u32 ENV_InsertResourceSet(void *prev, void *resSet);
extern void func_020913E8(void *p);
extern u32  func_0209C2B0(u32 a, u32 b);                         /* udiv */
extern double fabs(double x);
extern u32 _u32_div_f(u32 a, u32 b);
extern int func_020965B4(u8 *p, int i);
extern double func_0209AF34(double a, double b);
extern double frexp(double x, int *eptr);
extern double ldexp(double x, int n);
extern u64 func_0209C554(double x);
extern double copysign(double x, double y);                        /* copysign */
extern double pow(double x, double y);                        /* pow */
void SHA1_HMAC_Init(u32 a);
void SHA1_HMAC_Update(u32 a, u32 b, u32 c);
void SHA1_HMAC_GetHash(u32 a, u32 b);
void SHA1_HMAC_Calc(u32 a, u32 b, u32 c, u32 d, u32 e);
extern double func_0209C5E0(double x);
extern double scalbn(double x, int n);
extern int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const i32 *ipio2);
void MSL_C_LIB_EmptyStub(void);
void MSL_C_LIB_TwlCall1(u32 arg0);
void MSL_C_LIB_TwlCall3(u32 arg0, u32 arg1, u32 arg2);
void MSL_C_LIB_TwlCall2(u32 arg0, u32 arg1);
void MSL_C_LIB_TwlCall5(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
void MSL_C_LIB_SetTwlFlag(int x);
u32 MSL_C_LIB_LockRegisterDestructor(u32 arg);
double nan(const char *tagp);
void *MSL_C_LIB_AllocAllFromHeap(u32 heap);
void MSL_C_LIB_FreeToHeap(u32 heap);
u32 MSL_C_LIB_PrependResourceSet(void *resSet);
void *MSL_C_LIB_AllocFromHeap(u32 heap);
void CRT_Free(u32 heap);
void *MSL_C_LIB_ReallocResource(u32 resSet, u32 heap);
void *MSL_C_LIB_Calloc(u32 count, u32 elem_size);
int MSL_C_LIB_FlushAllGated(void);
int MSL_C_LIB_FlushAll(void);
int abs(int value);
void MSL_C_LIB_NopBufferHookA(int a, void *b);
void MSL_C_LIB_NopBufferHookB(int a, void *b);
void __prep_buffer(struct MslStream *stream);
int __load_buffer(struct MslStream *stream, u32 *bytes_loaded, int mode);
int __flush_buffer(struct MslStream *stream, u32 *bytes_flushed);
int fread(void *ptr, u32 memb_size, u32 num_memb, u32 stream);
size_t __fread(void *ptr, size_t memb_size, size_t num_memb, FILE *file);
int fclose(u8 *stream);
int MSL_C_LIB_FlushStream(struct MslStream *stream);
int func_02091C40(const u8 *s1, const u8 *s2, int n);
int __ftell(struct MslStream *stream);
int ftell(u32 stream);
int __fseek(MslStream *stream, u32 pos, u32 whence);
int fseek(u32 stream, u32 pos, u32 whence);
int rewind(void *stream);
u32 MSL_C_LIB_PopCount64(u64 x);
int __signbitd(double x);
int __fpclassifyd(double x);
int MSL_C_LIB_MbrToWc(unsigned short *pwc, const unsigned char *s, unsigned int n);
int MSL_C_LIB_WcToMb(char *s, unsigned short wc);
u32 MSL_C_LIB_CallFormatHook(u32 *dst, u32 c);
u32 MSL_C_LIB_WideToNarrow(u8 *dst, const u16 *src, u32 max);
void *func_02092344(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *MSL_C_LIB_MemsetPtr(void *dest, int c, u32 n);
u8 *memchr(u8 *s, u32 c, u32 n);
int func_020923F0(const u8 *s1, const u8 *s2, u32 n);
void func_02092430(u8 *dest, u32 val, u32 count);
const uchar *parse_format(const uchar *format_string, va_list *arg, print_format *format);
unsigned char *long2str(long num, unsigned char *buff, print_format format);
unsigned char *longlong2str(long long num, unsigned char *buff, print_format format);
unsigned char *double2hex(double num, unsigned char *buff, print_format format);
void round_decimal(Ctr *b, int idx);
unsigned char *float2str(double num, unsigned char *buff, print_format format);
int __pformatter(void *(*WriteProc)(void *, const uchar *, size_t), void *WriteProcArg, const uchar *format_str, va_list arg, int is_secure);
u32 MSL_C_LIB_SprintfWriteProc(u8 *sb, const void *src, u32 n);
u32 vsnprintf(u8 *dst, u32 n, const u8 *format, u8 *ap);
u32 sprintf(char *dst, u32 fmt, ...);
void qsort(void *table_base, size_t num_members, size_t member_size, _compare_function compare_members);
u32 func_02094694(void);
void srand(u32 v);
int MSL_C_LIB_StrReadProc(u32 *state, u32 ch, u32 mode);
void MSL_C_LIB_CallExitHook(u32 a, u32 b, u32 c);
void MSL_C_LIB_DefaultExitHook(void);
int strlen(const u8 *s);
char *strcpy(char *dst, const char *src);
u8 *strncpy(u8 *dest, const u8 *src, u32 n);
u8 *strcat(u8 *dest, const u8 *src);
int strcmp(const char *s1, const char *s2);
int strncmp(const u8 *s1, const u8 *s2, u32 n);
u8 *strchr(const u8 *s, int c);
int strcspn(const u8 *s, const u8 *reject);
u8 *strstr(const u8 *s1, const u8 *s2);
double __strtold(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *overflow);
u64 strtod(u32 s, u32 *endptr);
int atof(char *s);
u32 __strtoul(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
u32 strtoul(u32 s, u32 *endptr, u32 base);
int strtol(u32 s, u32 *endptr, u32 base);
u64 __strtoull(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
s64 strtoll(u32 s, u32 *endptr, u32 base);
int atoi(u32 s);
long long atoll(u32 s);
int fwide(u8 *stream, int orientation);
int wcslen(const u16 *s);
u16 *wcscpy(u16 *d, const u16 *s);
int MSL_C_LIB_ShouldRoundUp(u8 *dec, int idx);
void MSL_C_LIB_IncrementDigits(u8 *dec, int idx);
void MSL_C_LIB_SetPrecision(DB *dec, int precision);
void __ull2dec(decimal2 *result, u64 val);
void __timesdec(decimal2 *result, const decimal2 *x, const decimal2 *y);
void __str2dec(struct MslDecString *dec, const u8 *s, u16 exponent);
void __two_exp(decimal2 *result, long exp);
int __equals_dec(MslStrRec *a, MslStrRec *b);
int __less_dec(MslStrRec *a, MslStrRec *b);
void __minus_dec(decimal2 *z, const decimal2 *x, const decimal2 *y);
void __num2dec(DB *r, double x);
void __dtoa(const decform *f, double x, decimal *p);
double __dec2num(const decimal2 *d);
double __ieee754_pow(double x, double y);
int __ieee754_rem_pio2(double x, double *y);
double __kernel_cos(double x, double y);
extern u8 gMslTwlFlag;
extern struct MslRefBlock gMslRefToken;
extern u32 g_02153B8C;
extern u32 g_02153BB0;
extern u8 gMslMutexTable[];
extern int g_020A8818;
extern u8 gMslStream0[];
extern u32 gMslRefGen[];
extern u32 gMslRefCount[];
extern const u8 __tolower_map[];
extern u8  gMslStream1[];
extern u8  gMslStream2[];
extern unsigned char gMslFormatHook[];
extern const unsigned short __ctype_map[];
extern char sMslNegInf[5]; /* "-INF" */
extern char sMslNegInfLower[5]; /* "-inf" */
extern char sMslPosInf[4]; /* "INF"  */
extern char sMslPosInfLower[4]; /* "inf"  */
extern char sMslNegNan[5]; /* "-NAN" */
extern char sMslNegNanLower[5]; /* "-nan" */
extern char sMslPosNan[4]; /* "NAN"  */
extern char sMslPosNanLower[4]; /* "nan"  */
extern wchar_t sMslWideEmpty[];  /* L"" */
extern uchar sMslNarrowEmpty[];     /* ""  */
extern u32 MslRandSeed;
extern MslExitHook gMslExitHook;
extern const u8 __upper_map[];
extern float __float_huge;
extern double __double_huge;
extern const model9 s_infinity;
extern const model5 s_nan;
extern const char s_020A8ABC[];
extern const char s_020A8AEC[];
extern const char s_020A8B14[];
extern const char s_020A8B2C[];
extern const char s_020A8B3C[];
extern const char s_020A8B44[];
extern const char s_020A8B4C[];
extern const char s_020A8B54[];
extern const char s_020A8B5C[];
extern const char s_020A8B60[];
extern const char s_020A8B64[];
extern const char s_020A8B68[];
extern const char s_020A8B6C[];
extern const char s_020A8B70[];
extern const char s_020A8B74[];
extern const char s_020A8B78[];
extern const char s_020A8B7C[];
extern const char s_020A8B80[];
extern const char s_020A8B84[];
extern const char s_020A8B88[];
extern const char s_020A8B8C[];
extern const double pow_10[8];
extern const char s_020A8B90[];     /* "179769313486231580793728714053034151" */
extern int errno;
extern const float __float_nan;
extern const double bp[];
extern const double dp_h[];
extern const double dp_l[];
extern const i32 npio2_hw[];
extern const i32 two_over_pi[];



void MSL_C_LIB_EmptyStub(void)
{

}



#pragma thumb on



/*
 * Thumb wrapper over the ARM-side entry: aborts when the check fails, then
 * hands the argument across the Thumb/ARM stub at 0x020911F0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_TwlCall1.c \
 *       --func MSL_C_LIB_TwlCall1 --addr 0x020911D8 --cc 1.1p1 --thumb
 */
void MSL_C_LIB_TwlCall1(u32 arg0)
{
    if (OSi_IsRunOnTwl() == 0) {
        OS_Terminate();
    }
    SHA1_HMAC_Init(arg0);
}



/*
 * Three-argument flavour of MSL_C_LIB_TwlCall1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_TwlCall3.c \
 *       --func MSL_C_LIB_TwlCall3 --addr 0x02091200 --cc 1.1p1 --thumb
 */
void MSL_C_LIB_TwlCall3(u32 arg0, u32 arg1, u32 arg2)
{
    if (OSi_IsRunOnTwl() == 0) {
        OS_Terminate();
    }
    SHA1_HMAC_Update(arg0, arg1, arg2);
}



/*
 * Two-argument flavour of MSL_C_LIB_TwlCall1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_TwlCall2.c \
 *       --func MSL_C_LIB_TwlCall2 --addr 0x02091230 --cc 1.1p1 --thumb
 */
void MSL_C_LIB_TwlCall2(u32 arg0, u32 arg1)
{
    if (OSi_IsRunOnTwl() == 0) {
        OS_Terminate();
    }
    SHA1_HMAC_GetHash(arg0, arg1);
}



/*
 * Five-argument flavour: the fifth parameter is spilled back to [sp] for the
 * ARM-side callee, which is why the frame carries one extra word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_TwlCall5.c \
 *       --func MSL_C_LIB_TwlCall5 --addr 0x0209125C --cc 1.1p1 --thumb
 */
void MSL_C_LIB_TwlCall5(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    if (OSi_IsRunOnTwl() == 0) {
        OS_Terminate();
    }
    SHA1_HMAC_Calc(arg0, arg1, arg2, arg3, arg4);
}



#pragma thumb reset



/*
 * The image keeps BOTH arms predicated (`movne r1, #1` ... `moveq r1, #0`).
 * A single `x != 0` test lets 1.1p1 drop the first predicate (plain
 * `mov r1, #1`, one byte out, ~80 spellings in docs/notes/MSL_C_LIB_SetTwlFlag.c.txt).
 * A two-term `&&` condition goes through the short-circuit if-conversion
 * path, which predicates both arms; the redundant second test is folded away
 * afterwards, leaving the single `cmp r0, #0`.  Same shape in 1.1p1 matched
 * code: src/matched/GFL_NET_SYSTEM_InitDevice.c (`if (a && b) flag = 1;`).
 */
void MSL_C_LIB_SetTwlFlag(int x)
{
    u8 v;

    if (x && x) {
        v = 1;
    } else {
        v = 0;
    }
    gMslTwlFlag = v;
}



/*
 *           `bl` at +0x90 inside this very function.  `label` needs a site from
 *           outside 020912A8..02091374 and there is none, and MSL_CONSOLE_IO_RegisterDestructor is
 *           itself parked at MATCH in src/pending/MSL_CONSOLE_IO_RegisterDestructor.c, so the
 *           `matched` class has no manifest entry to cite either.  Filing the
 *           callee is the fix, but it lives in pkt_0209D728, which is not one
 *           of this lane's packets (write-set rule 9).
 *
 * harness output:
 *   MATCH  compiled 204 = original 204, 7 of 8 sites resolved
 *     +0010 OS_TryLockMutex [label x20]   +0070 OS_LockMutex [label x25]
 *     +0090 MSL_CONSOLE_IO_RegisterDestructor [UNRESOLVED - no witness outside this range]
 *     +00B0 func_02086078 [label x25]
 *     +00BC gMslMutexTable [literal x15]    +00C0 gMslRefToken [literal x60]
 *     +00C4 g_02153B8C [literal x15]    +00C8 g_02153BB0 [literal x15]
 *   every concrete byte right, no wildcard byte is inside a branch opcode.
 */
u32 MSL_C_LIB_LockRegisterDestructor(u32 arg)
{
    u32 r;

    if (OS_TryLockMutex(gMslMutexTable) == 0) {
        g_02153B8C = gMslRefToken.refs[0x1b];
        g_02153BB0 = 1;
    } else if (g_02153B8C == gMslRefToken.refs[0x1b]) {
        g_02153BB0 = g_02153BB0 + 1;
    } else {
        OS_LockMutex(gMslMutexTable);
        g_02153B8C = gMslRefToken.refs[0x1b];
        g_02153BB0 = 1;
    }
    r = MSL_CONSOLE_IO_RegisterDestructor(arg);
    if (--g_02153BB0 == 0) {
        func_02086078(gMslMutexTable);
    }
    return r;
}



double nan(const char *tagp)
{
    return func_0209BD38(g_020A8818);
}



void *MSL_C_LIB_AllocAllFromHeap(u32 heap)
{
    return OS_AllocFromHeap(0, (u32)-1, heap);
}



void MSL_C_LIB_FreeToHeap(u32 heap)
{
    OS_FreeToHeap(0, (u32)-1, heap);
}



/*
 * note:     env_system.o ENV_PrependResourceSet; target named OS_ReferentSize by libmatch.
 */
u32 MSL_C_LIB_PrependResourceSet(void *resSet)
{
    return ENV_InsertResourceSet(0, resSet);
}



void *MSL_C_LIB_AllocFromHeap(u32 heap)
{
    if (heap == 0)
        return 0;
    return MSL_C_LIB_AllocAllFromHeap(heap);
}



void CRT_Free(u32 heap)
{
    if (heap) {
        MSL_C_LIB_FreeToHeap(heap);
    }
}



/*
 *           callees func_020913E8 and MSL_C_LIB_PrependResourceSet have no witness
 *           outside 020913FC..0209146C (the only branches to them are
 *           the three sites inside this file), so those call sites stay
 *           wildcarded.  No C change is possible; the file becomes
 *           EXACT once either callee has its own shard entry.
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */
void *MSL_C_LIB_ReallocResource(u32 resSet, u32 heap)
{
    void *p;
    u32 n;

    if (resSet == 0)
        return MSL_C_LIB_AllocFromHeap(heap);
    if (heap == 0) {
        func_020913E8((void *)resSet);
        return 0;
    }
    n = MSL_C_LIB_PrependResourceSet((void *)resSet);
    p = MSL_C_LIB_AllocFromHeap(heap);
    if (p != 0) {
        if (n >= heap)
            n = heap;
        func_02092344(p, (const void *)resSet, n);
        func_020913E8((void *)resSet);
    }
    return p;
}



void *MSL_C_LIB_Calloc(u32 count, u32 elem_size)
{
    u32 size = elem_size;
    void *p;

    size = size * count;
    p = MSL_C_LIB_AllocFromHeap(size);
    if (p != 0)
        MSL_C_LIB_MemsetPtr(p, 0, size);
    return p;
}



/*
 * The gated sweep of gMslStream0: same three 0x4C-byte records as
 * MSL_C_LIB_FlushAll, but each record is only offered to MSL_C_LIB_FlushStream when three
 * bits of its own header agree, and the record is rejected as soon as any of
 * them fails.
 *
 * Two shapes carry the bytes:
 *
 *  - the 3-bit field at bits 7..9 of the record word at +4 has to be read as
 *    a bitfield, not as `(x << 22) >> 29`.  Writing the shifts out gives the
 *    same value but lets the register allocator put the loaded word in r2 and
 *    the extracted value in r1; the bitfield spelling puts the word in r1 and
 *    the extraction in r2, which is what the original has.  The pad member is
 *    what places the field at bit 7: a `lsl #0x16` (32 - (7 + 3)) extraction
 *    is only produced for a field whose offset is 7.
 *  - the middle test is `((x << 25) >> 30) & 1`, an unequal shift pair (the
 *    docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift
 *    shape) and not a bitfield read: `tst r1, #1` after a 2-bit extraction is
 *    bit 5 selected out of a two-bit field, which no single declaration
 *    produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_FlushAllGated.c \
 *       --func MSL_C_LIB_FlushAllGated --addr 0x0209149C --cc 1.1p1 --arm
 *   EXACT, 136 bytes, 2 relocation sites, both resolved.
 */
int MSL_C_LIB_FlushAllGated(void)
{
    u8 *p = gMslStream0;
    int i = 1;
    int r = 0;

    do {
        if (((struct MslFileKind *)(p + 4))->kind != 0 &&
            (((((struct MslStream *)p)->mode << 25) >> 30) & 1) != 0 &&
            ((struct MslStateBits *)(p + 8))->mode == 1) {
            if (MSL_C_LIB_FlushStream((struct MslStream *)p) != 0)
                r = -1;
        }
        p = (i < 3) ? gMslStream0 + i++ * 0x4c : 0;
    } while (p != 0);
    return r;
}



/*
 * Walks the three 0x4C-byte records of gMslStream0 and asks MSL_C_LIB_FlushStream
 * about every record whose +4 bitfield 3..5 is set, returning -1 as soon as
 * one of them fails and 0 otherwise.
 *
 * The two `!= 0` conditions are what put the gMslStream0 address in a
 * callee-saved register: the source names the global in the loop's own
 * advance expression (`p = (i < 3) ? gMslStream0 + i++ * 0x4c : 0`) rather
 * than binding it to a pointer local, so the loaded address is CSE'd into one
 * value that stays live across the MSL_C_LIB_FlushStream call and lands in r8, while
 * the cursor itself dies as that call's argument and lives in r0.  A `u8
 * *base` local instead sends the address to r5 and the induction variable to
 * r6, and the loop tail then renumbers (16 bytes of diff, and 0209149C's
 * sibling goes the same way).
 *
 * `i++ * 0x4c` rather than `i * 0x4c` is pinned by the increment sitting in
 * the true arm only: the whole ternary is if-converted, so the increment is
 * `addlt r5, r5, #1` and the false arm's 0 is rematerialised in its own
 * register (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_FlushAll.c \
 *       --func MSL_C_LIB_FlushAll --addr 0x02091524 --cc 1.1p1 --arm
 *   EXACT, 100 bytes, 2 relocation sites, both resolved.
 */
int MSL_C_LIB_FlushAll(void)
{
    u8 *p = gMslStream0;
    int i = 1;
    int r = 0;

    do {
        if (((((struct MslStream *)p)->mode << 22) >> 29) != 0) {
            if (MSL_C_LIB_FlushStream((struct MslStream *)p) != 0)
                r = -1;
        }
        p = (i < 3) ? gMslStream0 + i++ * 0x4c : 0;
    } while (p != 0);
    return r;
}



int abs(int value){ return value < 0 ? -value : value; }



void MSL_C_LIB_NopBufferHookA(int a, void *b){ }



void MSL_C_LIB_NopBufferHookB(int a, void *b){ }



/*
 * Three field moves on the object, in source order and nothing else:
 * `p->buffer_ptr = p->buffer; p->buffer_len = p->buffer_size - (p->position & p->buffer_alignment); p->saved_buffer_len = p->position;`.
 *
 * The load order (0x18, 0x2c, 0x1c, 0x20) is the scheduler hoisting the
 * second statement's two loads above the first statement's store, and the
 * register numbering ([r2, r1, ip, r3] for the four loads) follows from the
 * object being a struct: reading the fields through a `struct S *` keeps the
 * word loads independent, and the whole function is then a straight line with
 * no prologue at all.  No relocation sites, so the 40 bytes are compared
 * byte for byte with nothing wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__prep_buffer.c \
 *       --func __prep_buffer --addr 0x0209159C --cc 1.1p1 --arm
 *   EXACT, 40 bytes, no relocation sites.
 */
void __prep_buffer(struct MslStream *stream)
{
    stream->buffer_ptr = stream->buffer;
    stream->buffer_len = stream->buffer_size - (stream->position & stream->buffer_alignment);
    stream->saved_buffer_len = stream->position;
}



/*
 * One deferred transaction against the object: re-derive the working fields
 * (__prep_buffer), optionally preload the amount from the object's f20 when
 * the mode argument is 1, run the object's own f3c handler with four
 * arguments (f00, f1c, &f28 and f48 - the fourth is only visible as the dead
 * `ldr r3, [r4, #0x48]` the call does not otherwise need), publish f28 to the
 * caller's out parameter, and on success fold f28 into the running f18.
 *
 * The handler is called through a plain cast of the field
 * (`((Fn)p->read_proc)(...)`, i.e. the field itself declared as a function
 * pointer).  Spelling it as a guarded indirect call (`p->read_proc ? ... : 0`)
 * compiles to a branchy 102-byte-different body: the original is a bare
 * `blx ip`.
 *
 * The flag test is `((p->mode << 19) >> 31) == 0`, one bit selected out of the
 * word at +4; the unequal shift pair keeps both shifts (a mask would fold to
 * `tst #0x1000`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__load_buffer.c \
 *       --func __load_buffer --addr 0x020915C4 --cc 1.1p1 --arm
 *   EXACT, 140 bytes, 2 relocation sites, both resolved.
 */
int __load_buffer(struct MslStream *stream, u32 *bytes_loaded, int mode)
{
    u32 r;

    __prep_buffer((struct MslStream *)stream);
    if (mode == 1)
        stream->buffer_len = stream->buffer_size;
    r = ((MslReadFn)stream->read_proc)(stream->handle, stream->buffer, &stream->buffer_len, stream->ref_con);
    if (r == 2)
        stream->buffer_len = 0;
    if (bytes_loaded != 0)
        *bytes_loaded = stream->buffer_len;
    if (r != 0)
        return r;
    stream->position += stream->buffer_len;
    if (((stream->mode << 19) >> 31) == 0)
        MSL_C_LIB_NopBufferHookB(stream->buffer, &stream->buffer_len);
    return 0;
}



/*
 * The commit half of the pair whose prepare half is __load_buffer: work out
 * the amount still to apply (f24 - f1c), and if there is one, publish it to
 * f28, pre-process it through MSL_C_LIB_NopBufferHookA, run the object's f40 handler with
 * the same four arguments __load_buffer uses, hand f28 back through the out
 * parameter, and fold the applied amount into f18 on success.  The trailing
 * __prep_buffer and `return 0` are shared by both paths, which is why the
 * body's early exit is the loop-free `if (d != 0) { ... }` shape rather than a
 * `goto`.
 *
 * The handler is again a bare `blx ip` off a cast field; the f04 flag bit is
 * the same unequal-shift-pair test as in __load_buffer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__flush_buffer.c \
 *       --func __flush_buffer --addr 0x02091650 --cc 1.1p1 --arm
 *   EXACT, 132 bytes, 2 relocation sites, both resolved.
 */
int __flush_buffer(struct MslStream *stream, u32 *bytes_flushed)
{
    u32 d;
    u32 r;

    d = stream->buffer_ptr - stream->buffer;
    if (d != 0) {
        stream->buffer_len = d;
        if (((stream->mode << 19) >> 31) == 0)
            MSL_C_LIB_NopBufferHookA(stream->buffer, &stream->buffer_len);
        r = ((MslWriteFn)stream->write_proc)(stream->handle, stream->buffer, &stream->buffer_len, stream->ref_con);
        if (bytes_flushed != 0)
            *bytes_flushed = stream->buffer_len;
        if (r != 0)
            return r;
        stream->position += stream->buffer_len;
    }
    __prep_buffer((struct MslStream *)stream);
    return 0;
}



/*
 * A refcounted-resource wrapper: the 4-argument twin of
 * src/matched/fseek.c (which is the 3-argument one with a three-way
 * id dispatch).  The id here is the FOURTH argument and the dispatch is
 * two-way, `a3 == gMslStream0 ? 2 : 5`, which is what the image's
 * `mov r6,#2 / cmp r7,r4 / movne r6,#5` is.
 *
 * docs/notes/pkt_020916D4.c.txt records an earlier pass that got to 248
 * bytes against 256 and diagnosed the residue as a register tie on the
 * `mul` destination plus an unreachable CSE of the 0x02153B8C base.  Both
 * readings were wrong: the shortfall was an arm structure difference, not
 * an allocator tie.  The sibling's exact shape -- the `cur`/`ref` pair named
 * as two locals in the else arm, the two table stores written out in full in
 * BOTH the then arm and the inner else arm rather than factored, and
 * `gMslRefToken.refs[0x1b]` re-read at each of its three use sites -- closes
 * it with no permuter run at all.  The `str r3,[r2,r6,lsl #2]` addressing-
 * mode store and the per-site pool reloads the note despaired of follow from
 * writing the arms out rather than from any register hint.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/fread.c \
 *       --func fread --addr 0x020916D4 --arm --cc 1.1p1
 */
int fread(void *ptr, u32 memb_size, u32 num_memb, u32 stream)
{
    u32 idx = (stream == (u32)gMslStream0) ? 2 : 5;
    u8 *blk = gMslMutexTable + idx * 0x18;
    int r;

    if (OS_TryLockMutex(blk) == 0) {
        gMslRefGen[idx] = gMslRefToken.refs[0x1b];
        gMslRefCount[idx] = 1;
    } else {
        u32 cur = gMslRefGen[idx];
        u32 ref = gMslRefToken.refs[0x1b];

        if (cur == ref) {
            gMslRefCount[idx]++;
        } else {
            OS_LockMutex(blk);
            gMslRefGen[idx] = gMslRefToken.refs[0x1b];
            gMslRefCount[idx] = 1;
        }
    }
    r = __fread((void *)ptr, memb_size, num_memb, (struct FILE *)stream);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) func_02086078(blk);
    return r;
}



enum { __neutral, __writing, __reading, __rereading };



enum { __no_io_error, __io_error, __io_EOF };



/*
 * MSL C `__fread` (buffered stdio read), transcribed from the Metrowerks MSL
 * shape: fwide orientation probe, pushback drain through ungetc_buffer /
 * ungetwc_buffer, buffered copy loop through __load_buffer (__load_buffer)
 * and memcpy (func_02092344), then the unbuffered direct read that borrows
 * buffer/buffer_size.  Returns bytes_read / memb_size (func_0209C2B0).
 * The two levers over the earlier 788/456 note body were (1) writing it as
 * MSL writes it (always_buffer = !binary_io || buffer_mode == _IOFBF, the
 * set_error / set_eof bodies spelled out in each arm) and (2) the FILE
 * layout: eof/error are plain u8 members at +0x0c/+0x0d, NOT inside an
 * 8-byte state struct, which puts ungetc_buffer at +0x12 and ungetwc_buffer
 * at +0x14.  Project default compiler; EXACT on the first full transcription.
 */
size_t __fread(void *ptr, size_t memb_size, size_t num_memb, FILE *file)
{
    u8 *read_ptr;
    size_t num_bytes, bytes_requested, bytes_read;
    int ioresult, always_buffer;

    if (fwide((u8 *)file, 0) == 0)
        fwide((u8 *)file, -1);

    bytes_requested = memb_size * num_memb;

    if (!bytes_requested || file->error || file->mode.file_kind == 0)
        return 0;

    always_buffer = !file->mode.binary_io || file->mode.buffer_mode == 2;

    if (file->state.io_state == __neutral) {
        if (file->mode.io_mode & 1) {
            file->state.io_state = __reading;
            file->buffer_len = 0;
        }
    }

    if (file->state.io_state < __reading) {
        file->error = 1;
        file->buffer_len = 0;
        return 0;
    }

    if (file->mode.buffer_mode & 1) {
        if (MSL_C_LIB_FlushAllGated()) {
            file->error = 1;
            file->buffer_len = 0;
            return 0;
        }
    }

    read_ptr = (u8 *)ptr;
    bytes_read = 0;

    if (bytes_requested && file->state.io_state >= __rereading) {
        do {
            if (fwide((u8 *)file, 0) == 1) {
                *(u16 *)read_ptr = file->ungetwc_buffer[file->state.io_state - __rereading];
                read_ptr += sizeof(wchar_t);
                bytes_read += sizeof(wchar_t);
                bytes_requested -= sizeof(wchar_t);
            } else {
                *read_ptr++ = file->ungetc_buffer[file->state.io_state - __rereading];
                bytes_read++;
                bytes_requested--;
            }
            file->state.io_state--;
        } while (bytes_requested && file->state.io_state >= __rereading);

        if (file->state.io_state == __reading)
            file->buffer_len = file->saved_buffer_len;
    }

    if (bytes_requested && (file->buffer_len || always_buffer)) {
        do {
            if (!file->buffer_len) {
                ioresult = __load_buffer((struct MslStream *)file, 0, 0);
                if (ioresult) {
                    if (ioresult == __io_error) {
                        file->error = 1;
                        file->buffer_len = 0;
                    } else {
                        file->state.io_state = __neutral;
                        file->eof = 1;
                        file->buffer_len = 0;
                    }
                    bytes_requested = 0;
                    break;
                }
            }

            num_bytes = file->buffer_len;
            if (num_bytes > bytes_requested)
                num_bytes = bytes_requested;

            func_02092344(read_ptr, file->buffer_ptr, num_bytes);

            read_ptr += num_bytes;
            bytes_read += num_bytes;
            bytes_requested -= num_bytes;

            file->buffer_ptr += num_bytes;
            file->buffer_len -= num_bytes;
        } while (bytes_requested && always_buffer);
    }

    if (bytes_requested && !always_buffer) {
        u8 *save_buffer = file->buffer;
        size_t save_size = file->buffer_size;

        file->buffer = read_ptr;
        file->buffer_size = bytes_requested;

        ioresult = __load_buffer((struct MslStream *)file, &num_bytes, 1);
        if (ioresult) {
            if (ioresult == __io_error) {
                file->error = 1;
                file->buffer_len = 0;
            } else {
                file->state.io_state = __neutral;
                file->eof = 1;
                file->buffer_len = 0;
            }
        }

        bytes_read += num_bytes;

        file->buffer = save_buffer;
        file->buffer_size = save_size;

        __prep_buffer((struct MslStream *)file);

        file->buffer_len = 0;
    }

    return func_0209C2B0(bytes_read, memb_size);
}



int fclose(u8 *stream)
{
    u32 mode;
    int r;
    int x;

    if (stream == 0)
        return -1;
    mode = (((struct MslStream *)stream)->mode << 22) >> 29;
    if (mode == 0)
        return 0;
    r = (int)MSL_C_LIB_FlushStream((struct MslStream *)stream);
    x = ((int (*)(u32))*(u32 *)(stream + 0x44))(((struct MslStream *)stream)->handle);
    ((struct MslStream *)stream)->mode &= ~0x380u;
    ((struct MslStream *)stream)->handle = 0;
    if ((((struct MslStream *)stream)->state << 28) >> 31)
        return -1;
    return (r != 0 || x != 0) ? -1 : 0;
}



/*
 * The state machine the gMslStream0 sweep calls per record (and the entry the
 * null argument routes to MSL_C_LIB_FlushAll).  A record is rejected when its +0xd
 * byte is set or when its +4 field at bits 7..9 is zero, is a no-op when the
 * +4 field at bits 2..4 is 1, otherwise its +8 three-bit mode is forced to 2
 * when it is 3 or more (clearing the low three bits first), the record is
 * cleared when that mode is 2, and anything but mode 1 clears the mode and
 * returns.  Mode 1 runs the transaction __flush_buffer, and either sets the
 * +0xd byte and returns -1 or clears mode, +0x18 and +0x28 and returns 0.
 *
 * Every one of the five field accesses is a bitfield read/write against a
 * view struct cast onto the word, and that is load-bearing: written as
 * `(p->state << 29) >> 29` the three-mode tests are re-derived as `and #7` and
 * the whole tail renumbers, while a bitfield extraction is emitted as the
 * shift pair directly and is never folded (this is the same finding as
 * src/matched/MSL_C_LIB_FlushAllGated.c and MSL_C_LIB_FlushAll.c's neighbour).  The mode
 * writes come out as exactly `bic`/`orr` on the low three bits, which is what
 * a bitfield assignment emits, and the constant -1 the failure path returns is
 * derived by the compiler from the 1 it has just stored (`subne r0, r0, #2`).
 *
 * The `||` over the two rejection tests is what shares the `mvn r0, #0`
 * epilogue; two separate `if`s cost 20 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_FlushStream.c \
 *       --func MSL_C_LIB_FlushStream --addr 0x02091B5C --cc 1.1p1 --arm
 *   EXACT, 228 bytes, 2 relocation sites, both resolved.
 */
int MSL_C_LIB_FlushStream(struct MslStream *stream)
{
    int r;

    if (stream == 0)
        return MSL_C_LIB_FlushAll();
    if (stream->error != 0 || ((struct MslFileKind *)&stream->mode)->kind == 0)
        return -1;
    if (((struct MslFileIoBits *)&stream->mode)->io_mode == 1)
        return 0;
    if (((struct MslStateBits *)&stream->state)->mode >= 3)
        ((struct MslStateBits *)&stream->state)->mode = 2;
    if (((struct MslStateBits *)&stream->state)->mode == 2)
        stream->buffer_len = 0;
    if (((struct MslStateBits *)&stream->state)->mode != 1) {
        ((struct MslStateBits *)&stream->state)->mode = 0;
        return 0;
    }
    r = __flush_buffer((struct MslStream *)stream, 0);
    if (r != 0) {
        stream->error = 1;
        stream->buffer_len = 0;
        return -1;
    }
    ((struct MslStateBits *)&stream->state)->mode = 0;
    stream->position = 0;
    stream->buffer_len = 0;
    return 0;
}



/*
 * Bounded case-insensitive string compare (the `strncmp` twin of
 * src/matched/stricmp.c, which is the unbounded `strcmp`): each byte is
 * mapped through the 256-byte table at 0x020A60DC when it is below 0x80, then
 * compared as unsigned, for at most n bytes.
 *
 * Three spellings are load-bearing, and docs/notes/pkt_02091C40.c.txt records
 * a whole earlier pass that got the first two but not the third:
 *
 *  - the guard is `if (n > 0) { <loop> } return 0;`, not `if (n <= 0)
 *    return 0;`.  The early-return spelling predicates the guard
 *    (`movle r0,#0` / `pople`) and is 128 bytes; the block spelling branches
 *    to the single shared epilogue the image has at 0x02091CB0.
 *  - the two byte temps are the interleaved `int c1; u8 m1; int c2; u8 m2;`
 *    of the sibling, which is what colours the masked c1 into r4 and the raw
 *    c2 into r5.  Declaring the two masks together swaps those registers.
 *    Writing the masks as `c1 &= 0xff` on the `int`s instead (the earlier
 *    pass's spelling) leaves the same 26-byte register swap that note
 *    describes: lr/ip carry the loop counter and the table there, r4/ip here.
 *  - THE TABLE BASE IS ASSIGNED INSIDE THE GUARD.  `const u8 *tab =
 *    __tolower_map;` at the top of the function hoists its pool load above the
 *    `ble`, which is the last 12-byte residue: the image emits
 *    `mov lr,#0 / ble / ldr ip,[pc,#0x60]`, i.e. the table is not loaded at
 *    all on the n <= 0 path.  Declaring it at the top and assigning it in
 *    the block reproduces that order exactly.
 *
 * Also measured by the earlier pass, and still true: mwccarm 1.1p1 in
 * `-lang c99` mode REJECTS a C99 for-statement declaration
 * (`for (int i = 0; ...)` -> "expression syntax error"), so the counter is
 * declared at block scope.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02091C40.c \
 *       --func func_02091C40 --addr 0x02091C40 --arm --cc 1.1p1
 */
int func_02091C40(const u8 *s1, const u8 *s2, int n)
{
    const u8 *tab;
    int i = 0;
    int c1;
    u8 m1;
    int c2;
    u8 m2;

    if (n > 0)
    {
        tab = __tolower_map;
        do
        {
            c1 = *s1++;
            if (c1 >= 0 && c1 < 0x80)
                c1 = tab[c1];
            m1 = (u8)c1;

            c2 = *s2++;
            if (c2 >= 0 && c2 < 0x80)
                c2 = tab[c2];
            m2 = (u8)c2;

            if (m1 < m2)
                return -1;
            if (m1 > m2)
                return 1;
            if (m1 == 0)
                return 0;
            i++;
        } while (i < n);
    }
    return 0;
}



/*
 * Reads back the amount a record still owes: reject the record when its +4
 * bits 7..9 mode is neither 0 nor 1 or when its +0xd byte is set (leaving
 * 0x28 in the reserved word and returning -1), return the running f18 when
 * the +8 three-bit mode is 0, otherwise f34 + (f24 - f1c), reduced by
 * (mode - 2) for modes of 3 or more.
 *
 * Two spellings are pinned here and neither is the obvious one:
 *
 *  - `u8 sel = mode + 0xff;` is the decrement.  `mode - 1` compiles to
 *    `sub r1, r1, #1`; the original has `and #0xff; add r1, r1, #0xff;
 *    and #0xff`, i.e. the wrap-around add the source wrote, narrow once on
 *    being stored into the `u8 mode` and once on the sum
 *    (docs/idioms/a-u8-decrement-is-spelled-as-the-wraparound-add.md).
 *  - the +8 mode is read through a bitfield view struct.  A shift-pair
 *    spelling that feeds a `== 0` test is folded to `ands`, which loses both
 *    the second `lsr` and the register the original keeps.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__ftell.c \
 *       --func __ftell --addr 0x02091CBC --cc 1.1p1 --arm
 *   EXACT, 124 bytes, 1 relocation site, resolved.
 */
int __ftell(struct MslStream *stream)
{
    struct MslStateBits *m08 = (struct MslStateBits *)&stream->state;
    u8 mode;
    u8 sel;
    u32 m;
    u32 v;

    mode = ((struct MslFileKind *)&stream->mode)->kind;
    sel = mode + 0xff;
    if (sel > 1 || stream->error != 0) {
        errno = 0x28;
        return -1;
    }
    m = m08->mode;
    if (m == 0)
        return stream->position;
    v = stream->saved_buffer_len + (stream->buffer_ptr - stream->buffer);
    if (m >= 3)
        v -= m - 2;
    return v;
}



/*
 * The one-argument member of the refcounted-resource wrapper family
 * (src/matched/fseek.c is the three-argument one, and
 * src/matched/fread.c the four-argument one with a two-way dispatch).
 * Three-way id dispatch on a0, block base 0x02153BD4 with a 0x18 stride, the
 * two parallel arrays gMslRefGen / gMslRefCount, and the reference token
 * gMslRefToken.refs[0x1b].
 *
 * docs/notes/pkt_02091D38.c.txt left this at 265 of 268 bytes with a
 * three-instruction residue on the equality compare, and named the fix it had
 * not tried: bind BOTH sides to named locals in a nested if/else inside the
 * outer else, ARRAY ELEMENT FIRST --
 *
 *     u32 cur = gMslRefGen[idx];
 *     u32 ref = gMslRefToken.refs[0x1b];
 *     if (cur == ref) ... else ...
 *
 * not an `else if` on the bare expression.  Two live named temporaries on the
 * compare is what lands arr in r1 and the field in r0; the `else if` spelling
 * canonicalises either operand order to the swapped pair.  That spelling
 * closes it, exactly as the note predicted from 0x02092004.
 *
 * gMslRefToken is a two-word object whose SECOND word is the pointer: the pool
 * word is 0x02150FEC itself, so the field must be reached through
 * `gMslRefToken.refs`, never through a symbol named for 0x02150FF0.  The three
 * id constants are ADDRESSES compared against a0, so they are declared as
 * objects and their address taken; declaring them `u32` makes the compiler
 * dereference them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/ftell.c \
 *       --func ftell --addr 0x02091D38 --arm --cc 1.1p1
 */
int ftell(u32 stream)
{
    u32 idx = (stream == (u32)gMslStream0) ? 2 : (stream == (u32)gMslStream1) ? 3
            : (stream == (u32)gMslStream2) ? 4 : 5;
    u8 *blk = gMslMutexTable + idx * 0x18;
    int r;

    if (OS_TryLockMutex(blk) == 0) {
        gMslRefGen[idx] = gMslRefToken.refs[0x1b];
        gMslRefCount[idx] = 1;
    } else {
        u32 cur = gMslRefGen[idx];
        u32 ref = gMslRefToken.refs[0x1b];

        if (cur == ref) {
            gMslRefCount[idx]++;
        } else {
            OS_LockMutex(blk);
            gMslRefGen[idx] = gMslRefToken.refs[0x1b];
            gMslRefCount[idx] = 1;
        }
    }
    r = __ftell((struct MslStream *)stream);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) func_02086078(blk);
    return r;
}



/*
 * The seek (fseek shape) of the buffered-stdio object documented in
 * docs/families/cluster_02091588.h and cluster_02091AE8.h.  The real entry is
 * the push {r0-r3} home area at 0x02091E44 (the +0x38 handler takes &pos); the
 * listing's label at 0x02091E48 is the body, hence EXACT* against a 4-byte
 * listing extent until the seed at 0x02091E44 replaces it.
 *
 * Closed wave 12 after four lanes stalled at 448/28.  The two coupled residues
 * were both in the declarations, not the allocator:
 *   - the f08 state is a BITFIELD MEMBER OF THE STRUCT and is ASSIGNED as one
 *     (`((struct MslStateBits *)&p->state)->mode = 2;` / `= 0;`).  That is the `bic ip, #7 / orr #2` read-
 *     modify-write off the word the mode test already loaded, and the plain
 *     re-read after the store; no volatile view is involved.
 *   - the in-window test is `if (pos >= f18 || pos < f34) mode = 0; else
 *     {...}`: the disjunction's THEN arm is the `b` the image keeps between
 *     the two compares.  The positive `&&` form cross-jumps it away.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__fseek.c \
 *       --func __fseek --addr 0x02091E44 --arm --cc 1.1p1
 *   EXACT*, 448 bytes, 3 of 3 relocation sites resolved.
 *   ../2.0/sp2 and ../2.0/sp2p2: 488 bytes, DIFF.
 */
int __fseek(MslStream *stream, u32 pos, u32 whence)
{
    u8 mode;

    mode = ((struct MslFileModeBits *)&stream->mode)->kind;
    if (mode != 1 || stream->error != 0) {
        errno = 0x28;
        return -1;
    }
    if (((struct MslStateBits *)&stream->state)->mode == 1 && __flush_buffer((struct MslStream *)stream, 0) != 0) {
        stream->error = 1;
        stream->buffer_len = 0;
        errno = 0x28;
        return -1;
    }
    if (whence == 1) {
        whence = 0;
        pos += __ftell((struct MslStream *)stream);
    }
    if (whence != 2 && ((struct MslFileModeBits *)&stream->mode)->io_mode != 3 && ((struct MslStateBits *)&stream->state)->mode - 2 <= 1) {
        if (pos >= stream->position || pos < stream->saved_buffer_len) {
            ((struct MslStateBits *)&stream->state)->mode = 0;
        } else {
            stream->buffer_ptr = stream->buffer + (pos - stream->saved_buffer_len);
            stream->buffer_len = stream->position - pos;
            ((struct MslStateBits *)&stream->state)->mode = 2;
        }
    } else {
        ((struct MslStateBits *)&stream->state)->mode = 0;
    }
    if (((struct MslStateBits *)&stream->state)->mode == 0) {
        if (stream->seek_proc != 0 && stream->seek_proc(stream->handle, &pos, whence, stream->ref_con) != 0) {
            stream->error = 1;
            stream->buffer_len = 0;
            errno = 0x28;
            return -1;
        }
        stream->eof = 0;
        stream->position = pos;
        stream->buffer_len = 0;
    }
    return 0;
}



/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocking: label, no outside witness -- the one wildcard site is +0x00D4
 *           PC24 __fseek, whose only branch in the image is this call
 *           (match.py: "has no witness outside 02092004..02092120").  Cut
 *           does not help: the site is inside the single function, so
 *           --suggest-split has nothing to offer.  Byte-correct as it
 *           stands: converts with no edit the moment 0x02091E44 has a
 *           manifest entry of its own.
 */
int fseek(u32 stream, u32 pos, u32 whence)
{
    u32 idx = (stream == (u32)gMslStream0) ? 2 : (stream == (u32)gMslStream1) ? 3
            : (stream == (u32)gMslStream2) ? 4 : 5;
    u8 *blk = gMslMutexTable + idx * 0x18;
    int r;

    if (OS_TryLockMutex(blk) == 0) {
        gMslRefGen[idx] = gMslRefToken.refs[0x1b];
        gMslRefCount[idx] = 1;
    } else {
        u32 cur = gMslRefGen[idx];
        u32 ref = gMslRefToken.refs[0x1b];

        if (cur == ref) {
            gMslRefCount[idx]++;
        } else {
            OS_LockMutex(blk);
            gMslRefGen[idx] = gMslRefToken.refs[0x1b];
            gMslRefCount[idx] = 1;
        }
    }
    r = __fseek((MslStream *)stream, pos, whence);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) func_02086078(blk);
    return r;
}



int rewind(void *stream){ int result; ((struct MslStream *)((char *)(stream)))->error = (unsigned char)0; result = fseek((int)stream, (int)0, (int)0); ((struct MslStream *)((char *)(stream)))->error = (unsigned char)0; return result; }



/*
 * 64-bit population count: the four SWAR stages of the standard bit-count
 * idiom over an unsigned long long, then the horizontal fold.  The last three
 * folds are unmasked (`x += x >> 8`, `>> 16`, `>> 32`) because the count of
 * 64 bits can never carry out of a byte, so no 0x00FF00FF mask is needed.
 *
 * The 32-bit halves of the 64-bit shifts are what pin the type: `orr r3, r3,
 * r1, lsl #31` after `lsr r3, r0, #1` is a 64-bit `>> 1`, and `and r2, r2,
 * r1, lsr #1` masks the high word separately.  The three masks are 64-bit
 * constants whose two halves happen to be equal, which is why one pool word
 * each (0x55555555, 0x33333333, 0x0F0F0F0F) serves both words.
 *
 * `x + (x >> 32)` is not emitted as a shift at all: at that point the value
 * is under 0x100, so only the low half matters and mwcc folds the 64-bit add
 * to `adds r0, r1, r0` (low word plus high word) with the carry dropped.
 *
 * The listing extent (148 bytes) includes this function's three-word pool at
 * 0x020921CC..0x020921D4; nothing here is a relocation, so the whole range is
 * compared byte for byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_PopCount64.c \
 *       --func MSL_C_LIB_PopCount64 --addr 0x02092144 --cc 1.1p1 --arm
 *   EXACT, 148 bytes, no relocation sites.
 */
u32 MSL_C_LIB_PopCount64(u64 x)
{
    x = x - ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32);
    return (u32)x & 0xFF;
}



int __signbitd(double x)
{
    u32 *w = (u32 *)&x;

    return (w[1] & 0x80000000u) ? 1 : 0;
}



/*
 * note:     the trailing star is the unlabelled leaf at 0x02092264 (and the
 *           word-run of unlabelled leaves after it), not a byte difference:
 *           the listing extent runs to the next func_ label at 0x020922B0.
 *           Wants a seed at 0x02092264 in layout/function_starts.txt.
 */
int __fpclassifyd(double x)
{
    if ((*(u32 *)((char *)&x + 4) & 0x7FF00000u) != 0) {
        if ((*(u32 *)((char *)&x + 4) & 0x7FF00000u) == 0x7FF00000u)
            return ((*(u32 *)((char *)&x + 4) & 0xFFFFFu) != 0 ||
                    *(u32 *)&x != 0) ? 1 : 2;
    } else {
        return ((*(u32 *)((char *)&x + 4) & 0xFFFFFu) != 0 ||
                *(u32 *)&x != 0) ? 5 : 3;
    }
    return 4;
}



int MSL_C_LIB_MbrToWc(unsigned short *pwc, const unsigned char *s, unsigned int n)
{
    if (s == 0) {
        return 0;
    }
    if (n == 0) {
        return -1;
    }
    if (pwc != 0) {
        *pwc = *s;
    }
    if (*s == 0) {
        return 0;
    }
    return 1;
}



int MSL_C_LIB_WcToMb(char *s, unsigned short wc)
{
    if (s == 0) {
        return 0;
    }
    *s = wc;
    return 1;
}



u32 MSL_C_LIB_CallFormatHook(u32 *dst, u32 c)
{
    return ((MslFormatHookHolder *)gMslFormatHook)->hook->proc(dst, c);
}



u32 MSL_C_LIB_WideToNarrow(u8 *dst, const u16 *src, u32 max)
{
    u32 n = 0;
    u32 tmp;

    if (dst == 0 || src == 0)
        return 0;

    do {
        u32 k;

        if (*src == 0) {
            dst[n] = 0;
            break;
        }
        k = MSL_C_LIB_CallFormatHook(&tmp, *src++);
        if (n + k > max)
            break;
        strncpy(dst + n, (const u8 *)&tmp, k);
        n += k;
    } while (n <= max);

    return n;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Byte-wise memcpy (func_02092344) and memmove (memmove).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02092344.c \
 *       --addr 0x02092344 --arm
 */
void *func_02092344(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (n == 0) {
        return dest;
    }

    do {
        *d++ = *s++;
    } while (--n != 0);

    return dest;
}



void *memmove(void *dest, const void *src, size_t n)
{
    if ((const unsigned char *)src >= (unsigned char *)dest) {
        unsigned char *d = (unsigned char *)dest;
        const unsigned char *s = (const unsigned char *)src;

        if (n == 0) {
            return dest;
        }

        do {
            *d++ = *s++;
        } while (--n != 0);

        return dest;
    } else {
        const unsigned char *s = (const unsigned char *)src + n;
        unsigned char *d = (unsigned char *)dest + n;

        if (n == 0) {
            return dest;
        }

        do {
            *--d = *--s;
        } while (--n != 0);

        return dest;
    }
}



/*
 * String / memory utilities:
 *   MSL_C_LIB_MemsetPtr (20 B)  wraps func_02092430 (memset) and returns ptr
 *   memchr (44 B)  memchr (byte search)
 *   func_020923F0 (64 B)  memcmp (memory comparison)
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020923B0.c \
 *       --addr 0x020923B0
 */
void *MSL_C_LIB_MemsetPtr(void *dest, int c, u32 n)
{
    func_02092430(dest, c, n);
    return dest;
}



u8 *memchr(u8 *s, u32 c, u32 n)
{
    u8 val = (u8)c;

    if (n != 0) {
        do {
            if (*s++ == val) {
                return s - 1;
            }
        } while (--n != 0);
    }
    return 0;
}



int func_020923F0(const u8 *s1, const u8 *s2, u32 n)
{
    u8 b1;
    u8 b2;

    if (n != 0) {
        do {
            b1 = *s1++;
            b2 = *s2++;
            if (b1 != b2) {
                b1 = *(s1 - 1);
                b2 = *(s2 - 1);
                return (b1 < b2) ? -1 : 1;
            }
        } while (--n != 0);
    }
    return 0;
}



void func_02092430(u8 *dest, u32 val, u32 count)
{
    u32 byte_val;
    u32 align;
    u32 tmp;
    u32 blocks;
    u32 words;

    byte_val = val & 0xff;
    if (count >= 0x20) {
        align = (u32)(-(int)(u32)dest) & 3;
        if (align != 0) {
            count -= align;
            do {
                *dest++ = (u8)byte_val;
            } while (--align != 0);
        }

        if (byte_val != 0) {
            tmp = byte_val << 8;
            tmp |= (byte_val << 24) | (byte_val << 16);
            byte_val |= tmp;
        }

        blocks = count >> 5;
        if (blocks != 0) {
            do {
                ((MslMemsetBlock *)dest)->w0 = byte_val;
                ((MslMemsetBlock *)dest)->w1 = byte_val;
                ((MslMemsetBlock *)dest)->w2 = byte_val;
                ((MslMemsetBlock *)dest)->w3 = byte_val;
                ((MslMemsetBlock *)dest)->w4 = byte_val;
                ((MslMemsetBlock *)dest)->w5 = byte_val;
                ((MslMemsetBlock *)dest)->w6 = byte_val;
                ((MslMemsetBlock *)dest)->w7 = byte_val;
                dest += 0x20;
            } while (--blocks != 0);
        }

        words = (count & 0x1f) >> 2;
        if (words != 0) {
            do {
                ((MslMemsetBlock *)dest)->w0 = byte_val;
                dest += 4;
            } while (--words != 0);
        }

        count &= 3;
    }

    if (count != 0) {
        do {
            *dest++ = (u8)byte_val;
        } while (--count != 0);
    }
}



#define isdigit(c) ((unsigned int)(c) < 0x80 ? (__ctype_map[c] & 8) : 0)



/*
 * note:     MSL printf.c `parse_format`, the conversion-spec scanner that
 *           __pformatter (__pformatter) calls once per '%'.  Written from
 *           the Metrowerks source shape: `int c` and `int flag_found`, the
 *           flag loop as for(;;){flag_found = 1; switch; if (flag_found)
 *           c = *++s; else break;}, the length modifiers as a second switch
 *           with flag_found, `g`/`G` falling through into `e`/`E`, and the
 *           print_format struct copied out whole.  The two levers that
 *           closed it from 12 bytes out: isdigit's range test is UNSIGNED
 *           (`(unsigned int)c < 0x80`, the image's movhs/lsllo pair), and
 *           the length cases are ordered j, t, z (the image's arm bodies
 *           store 6, 8, 7 in that order).  All chars unsigned (ldrb).
 *           Under ../2.0/sp2 the same source is 1392 bytes; no pin.
 */
const uchar *parse_format(const uchar *format_string, va_list *arg, print_format *format)
{
    print_format f;
    const uchar *s = format_string;
    int c;
    int flag_found;

    f.justification_options = 1;
    f.sign_options = 0;
    f.precision_specified = 0;
    f.alternate_form = 0;
    f.argument_options = 0;
    f.field_width = 0;
    f.precision = 0;

    if ((c = *++s) == '%') {
        f.conversion_char = c;
        *format = f;
        return s + 1;
    }

    for (;;) {
        flag_found = 1;
        switch (c) {
        case '-':
            f.justification_options = 0;
            break;
        case '+':
            f.sign_options = 1;
            break;
        case ' ':
            if (f.sign_options != 1)
                f.sign_options = 2;
            break;
        case '#':
            f.alternate_form = 1;
            break;
        case '0':
            if (f.justification_options != 0)
                f.justification_options = 2;
            break;
        default:
            flag_found = 0;
        }
        if (flag_found)
            c = *++s;
        else
            break;
    }

    if (c == '*') {
        if ((f.field_width = va_arg(*arg, int)) < 0) {
            f.justification_options = 0;
            f.field_width = -f.field_width;
        }
        c = *++s;
    } else {
        while (isdigit(c)) {
            f.field_width = (f.field_width * 10) + (c - '0');
            c = *++s;
        }
    }

    if (f.field_width > 509) {
        f.conversion_char = 0xFF;
        *format = f;
        return s + 1;
    }

    if (c == '.') {
        f.precision_specified = 1;
        if ((c = *++s) == '*') {
            if ((f.precision = va_arg(*arg, int)) < 0)
                f.precision_specified = 0;
            c = *++s;
        } else {
            while (isdigit(c)) {
                f.precision = (f.precision * 10) + (c - '0');
                c = *++s;
            }
        }
    }

    flag_found = 1;

    switch (c) {
    case 'h':
        f.argument_options = 2;
        if (s[1] == 'h') {
            f.argument_options = 1;
            c = *++s;
        }
        break;
    case 'l':
        f.argument_options = 3;
        if (s[1] == 'l') {
            f.argument_options = 4;
            c = *++s;
        }
        break;
    case 'L':
        f.argument_options = 9;
        break;
    case 'j':
        f.argument_options = 6;
        break;
    case 't':
        f.argument_options = 8;
        break;
    case 'z':
        f.argument_options = 7;
        break;
    default:
        flag_found = 0;
    }

    if (flag_found)
        c = *++s;

    f.conversion_char = c;

    switch (c) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
        if (f.argument_options == 9) {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified)
            f.precision = 1;
        else if (f.justification_options == 2)
            f.justification_options = 1;
        break;

    case 'f':
    case 'F':
        if (f.argument_options == 2 || f.argument_options == 6 ||
            f.argument_options == 7 || f.argument_options == 8 ||
            f.argument_options == 4) {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified)
            f.precision = 6;
        break;

    case 'a':
    case 'A':
        if (!f.precision_specified)
            f.precision = 13;
        if (f.argument_options == 2 || f.argument_options == 6 ||
            f.argument_options == 7 || f.argument_options == 8 ||
            f.argument_options == 4 || f.argument_options == 1)
            f.conversion_char = 0xFF;
        break;

    case 'g':
    case 'G':
        if (!f.precision)
            f.precision = 1;
    case 'e':
    case 'E':
        if (f.argument_options == 2 || f.argument_options == 1 ||
            f.argument_options == 6 || f.argument_options == 7 ||
            f.argument_options == 8 || f.argument_options == 4) {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified)
            f.precision = 6;
        break;

    case 'p':
        f.conversion_char = 'x';
        f.alternate_form = 1;
        f.argument_options = 3;
        f.precision = 8;
        break;

    case 'c':
        if (f.argument_options == 3)
            f.argument_options = 5;
        else if (f.precision_specified || f.argument_options != 0)
            f.conversion_char = 0xFF;
        break;

    case 's':
        if (f.argument_options == 3)
            f.argument_options = 5;
        else if (f.argument_options != 0)
            f.conversion_char = 0xFF;
        break;

    case 'n':
        if (f.argument_options == 9)
            f.conversion_char = 0xFF;
        break;

    default:
        f.conversion_char = 0xFF;
        break;
    }

    *format = f;
    return s + 1;
}



/*
 * note:     MSL printf.c `long2str`: the 32-bit integer conversion of the
 *           printf back end, written as the MSL source has it.  The format
 *           descriptor is MSL's 16-byte `print_format` passed BY VALUE
 *           (six u8 option bytes, then int field_width at +8 and int
 *           precision at +0xC), which is what the home-area push and the
 *           [sp,#0x40..0x4c] reads are.  The dead 64-bit INT_MIN guard in
 *           the image (`asr r0,sl,#31; cmp r0,#0x80000000; cmpeq sl,#0`) is
 *           the source comparing the 32-bit `num` against the 64-bit
 *           constant 0x8000000000000000 (LLONG_MIN), promoted.  The digit
 *           pointer is `unsigned char *` (the `*p != '0'` test is ldrb).
 */
unsigned char *long2str(long num, unsigned char *buff, print_format format)
{
    unsigned long unsigned_num, base;
    unsigned char *p;
    int n, digits;
    int minus = 0;

    unsigned_num = num;
    minus = 0;
    p = buff;
    *--p = 0;
    digits = 0;

    if (!num && !format.precision && !(format.alternate_form && format.conversion_char == 'o'))
        return p;

    switch (format.conversion_char) {
    case 'd':
    case 'i':
        base = 10;
        if (num < 0) {
            if (num != 0x8000000000000000LL)
                unsigned_num = -num;
            minus = 1;
        }
        break;
    case 'o':
        base = 8;
        format.sign_options = 0;
        break;
    case 'u':
        base = 10;
        format.sign_options = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        format.sign_options = 0;
        break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;
        if (n < 10)
            n += '0';
        else {
            n -= 10;
            if (format.conversion_char == 'x')
                n += 'a';
            else
                n += 'A';
        }
        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format.alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.justification_options == 2) {
        format.precision = format.field_width;
        if (minus || format.sign_options)
            --format.precision;
        if (base == 16 && format.alternate_form)
            format.precision -= 2;
    }

    if (buff - p + format.precision > 509)
        return 0;

    while (digits < format.precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format.alternate_form) {
        *--p = format.conversion_char;
        *--p = '0';
    }

    if (minus)
        *--p = '-';
    else if (format.sign_options == 1)
        *--p = '+';
    else if (format.sign_options == 2)
        *--p = ' ';

    return p;
}



/*
 * note:     MSL printf.c `longlong2str`, the 64-bit twin of long2str
 *           (same source template over long long).  This is the REAL entry:
 *           the listing labels 0x02092C38 as a 4-byte row and 0x02092C3C as
 *           the function, but 0x02092C38 is the home-area push
 *           {r0,r1,r2,r3} that saves no lr, so disasm.py placed the label
 *           four bytes late.  Wants a seed at 0x02092C38 in
 *           layout/function_starts.txt and the label at 0x02092C3C removed
 *           (that is also what the trailing star is: the listing extent at
 *           0x02092C38 is 4 bytes, the body is 724).  `%` and `/` on
 *           unsigned long long emit _ull_mod / _ll_udiv, the standard mwcc
 *           names of the two runtime divmod entry points.
 */
unsigned char *longlong2str(long long num, unsigned char *buff, print_format format)
{
    unsigned long long unsigned_num, base;
    unsigned char *p;
    int n, digits;
    int minus = 0;

    unsigned_num = num;
    minus = 0;
    p = buff;
    *--p = 0;
    digits = 0;

    if (!num && !format.precision && !(format.alternate_form && format.conversion_char == 'o'))
        return p;

    switch (format.conversion_char) {
    case 'd':
    case 'i':
        base = 10;
        if (num < 0) {
            if (num != 0x8000000000000000LL)
                unsigned_num = -num;
            minus = 1;
        }
        break;
    case 'o':
        base = 8;
        format.sign_options = 0;
        break;
    case 'u':
        base = 10;
        format.sign_options = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        format.sign_options = 0;
        break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;
        if (n < 10)
            n += '0';
        else {
            n -= 10;
            if (format.conversion_char == 'x')
                n += 'a';
            else
                n += 'A';
        }
        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format.alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.justification_options == 2) {
        format.precision = format.field_width;
        if (minus || format.sign_options)
            --format.precision;
        if (base == 16 && format.alternate_form)
            format.precision -= 2;
    }

    if (buff - p + format.precision > 509)
        return 0;

    while (digits < format.precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format.alternate_form) {
        *--p = format.conversion_char;
        *--p = '0';
    }

    if (minus)
        *--p = '-';
    else if (format.sign_options == 1)
        *--p = '+';
    else if (format.sign_options == 2)
        *--p = ' ';

    return p;
}



/*
 * note:     MSL printf.c `double2hex`, the `%a`/`%A` formatter.  REAL
 *           entry: 0x02092F0C is the home-area push {r0,r1,r2,r3}; the
 *           listing label sits four bytes late at 0x02092F10 (the trailing
 *           star is that 4-byte listing extent, the body is 1196 bytes with
 *           its pool).  Wants a seed at 0x02092F0C and the 0x02092F10 label
 *           removed.  Callees: __dtoa = __num2dec, long2str =
 *           long2str (for the binary exponent), fabs = fabs,
 *           0x0209BAC8 = the runtime double `!=` (__dcmp_6 in
 *           layout/runtime_arm9.txt).
 *           The inf/nan spellings are MSL's `strcpy(p, "-INF")` etc.; the
 *           image copies them with mwcc's `__memcpy` intrinsic, paired
 *           ldrb/strb with the source in r3.  Written as __memcpy from a
 *           NON-const `char[N]` extern (a C string literal's own type): a
 *           struct copy, or __memcpy from a `const char[]`, reorders the
 *           loads and moves the source to r1.  The byte-swap loop walks a
 *           named pointer `b` to num (the permuter's lever: without it the
 *           index and base registers trade places).
 */
unsigned char *double2hex(double num, unsigned char *buff, print_format format)
{
    unsigned char *p;
    unsigned char *q;
    unsigned char working_byte;
    double ld;
    long exp;
    print_format exp_format;
    int hex_precision;
    int mantissa_bit;
    unsigned long snum;
    decform form;
    decimal dec;
    int i;
    unsigned char *b;

    p = buff;
    ld = num;

    if (format.precision > 509)
        return 0;

    form.style = 0;
    form.digits = 0x20;
    __dtoa(&form, num, &dec);

    switch (dec.sig.text[0]) {
    case '0':
        dec.exp = 0;
        break;
    case 'I':
        if (dec.sgn) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                __memcpy(p, sMslNegInf, 5);
            else
                __memcpy(p, sMslNegInfLower, 5);
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                __memcpy(p, sMslPosInf, 4);
            else
                __memcpy(p, sMslPosInfLower, 4);
        }
        return p;
    case 'N':
        if (dec.sgn) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                __memcpy(p, sMslNegNan, 5);
            else
                __memcpy(p, sMslNegNanLower, 5);
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                __memcpy(p, sMslPosNan, 4);
            else
                __memcpy(p, sMslPosNanLower, 4);
        }
        return p;
    }

    exp_format.justification_options = 1;
    exp_format.sign_options = 1;
    exp_format.precision_specified = 0;
    exp_format.alternate_form = 0;
    exp_format.argument_options = 0;
    exp_format.field_width = 0;
    exp_format.precision = 1;
    exp_format.conversion_char = 'd';

    b = (unsigned char *)&num;
    for (i = 0; i < 4; i++) {
        unsigned char t = b[i];
        b[i] = b[7 - i];
        b[7 - i] = t;
    }

    snum = ((unsigned char *)&num)[0] << 25;
    snum |= ((unsigned char *)&num)[1] << 17;
    snum = (snum >> 21) & 0x7FF;
    if (snum)
        exp = snum - 0x3FF;
    else
        exp = 0;

    p = long2str(exp, buff, exp_format);
    if (format.conversion_char == 'a')
        *--p = 'p';
    else
        *--p = 'P';

    q = (unsigned char *)&num;
    for (hex_precision = format.precision, mantissa_bit = hex_precision * 4 + 11;
         hex_precision >= 1; --hex_precision, mantissa_bit -= 4) {
        if (mantissa_bit < 64) {
            working_byte = q[mantissa_bit >> 3] >> (7 - (mantissa_bit & 7));
            if ((mantissa_bit & ~7) != ((mantissa_bit - 4) & ~7))
                working_byte |= ((q[(mantissa_bit >> 3) - 1] << 8) >> (7 - (mantissa_bit & 7)));
            working_byte &= 0x0f;
            if (working_byte < 10)
                working_byte += '0';
            else if (format.conversion_char == 'a')
                working_byte += 'a' - 10;
            else
                working_byte += 'A' - 10;
        } else
            working_byte = '0';
        *--p = working_byte;
    }

    if (format.precision || format.alternate_form)
        *--p = '.';

    if (fabs(ld) != 0.0)
        *--p = '1';
    else
        *--p = '0';

    if (format.conversion_char == 'a')
        *--p = 'x';
    else
        *--p = 'X';
    *--p = '0';

    if (dec.sgn)
        *--p = '-';
    else if (format.sign_options == 1)
        *--p = '+';
    else if (format.sign_options == 2)
        *--p = ' ';

    return p;
}



/*
 * MSL printf back end: the decimal rounding / odometer carry on the digit
 * buffer `__num2dec`-style control block.  Rounds the ASCII digit string in
 * place at position `idx`, propagating a carry leftwards, and renormalises
 * the exponent field when the carry runs off the top.
 *
 *   +0x00  u16 unk0
 *   +0x02  s16 num     decimal exponent (ldrsh at 0x020934A0, strh at reset)
 *   +0x04  u8  len     significant-digit count
 *   +0x05  u8  str[]   '0'..'9' ASCII digits
 *
 * THE ONE SPELLING THAT MATTERS (this closed a 12-byte residue that four
 * earlier lanes could not move; see docs/notes/pkt_020933B8.c.txt for the
 * seven spellings that all landed on the same 264-byte if-converted form).
 * The carry loop must be a `while (idx != 0)` whose DECREMENT lives inside
 * the continue path, not a `for (; idx != 0; idx--)`:
 *
 *     if (carry != 0 || v == 0) { idx--; continue; }
 *     *q = (u8)(v + '0');
 *     break;
 *
 * Written as a `for` (or with the break arm as the positive condition),
 * mwcc 1.1p1 if-converts the two-instruction write arm to `addne`/`strbne`
 * and fuses the decrement into `subs r1, r1, #1`, which is 12 bytes short.
 * With the decrement on the continue path the write arm is no longer on the
 * fall-through, so it stays a real block (`add ip, r4, #0x30` / `strb ip,
 * [r3]` / `b END`) and the loop test stays its own `cmp r1, #0` / `bne`,
 * exactly as the image has it at 0x0209347C..0x02093494.
 *
 * Two spellings carried over from the note and still required:
 *   - the reset block is `len = 1; num = 0; str[0] = '0';` in that order;
 *   - the `idx == 0` tail must be an explicit `goto reset;` back into the
 *     `idx < 0` block, or the 5-instruction reset is duplicated inline.
 *
 * The trailing star is the unlabelled follower at 0x020934CC (a
 * `push {r0, r1, r2, r3}` argument home area, the real start of the
 * function disasm.py labels at 0x020934D0): the listing extent runs 280
 * bytes, the body is 276.  Wants a seed at 0x020934CC in
 * layout/function_starts.txt.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/round_decimal.c \
 *       --func round_decimal --addr 0x020933B8 --arm --cc 1.1p1
 *   EXACT*, 276 bytes, no relocation sites.
 */
void round_decimal(Ctr *b, int idx)
{
    u8 *p;
    u8 *q;
    u32 v;
    u32 carry;

    if (idx < 0) {
    reset:
        b->length = 1;
        b->exp = 0;
        b->digits[0] = '0';
        return;
    }
    if (idx >= b->length)
        return;
    p = b->digits;
    q = p + idx + 1;
    v = (u8)(*--q - '0');
    if (v == 5) {
        u8 *s = p + b->length;
        do {
            s--;
        } while (s > q && *s == '0');
        if (s == q)
            carry = (u8)q[-1] & 1;
        else
            carry = 1;
    } else {
        carry = v > 5;
    }
    while (idx != 0) {
        v = (u8)((*--q - '0') + carry);
        carry = v > 9;
        if (carry != 0 || v == 0) {
            idx--;
            continue;
        }
        *q = (u8)(v + '0');
        break;
    }
    if (carry != 0) {
        b->exp = b->exp + 1;
        b->length = 1;
        b->digits[0] = '1';
        return;
    }
    if (idx == 0)
        goto reset;
    b->length = (u8)idx;
}



static inline int isupper(int c) { return ((c < 0 || c >= 0x80) ? 0 : (__ctype_map[c] & 0x200)); }



/*
 * note:     MSL printf.c `float2str`, the %e/%f/%g formatter.  REAL entry:
 *           0x020934CC is the home-area push {r0,r1,r2,r3}; the listing
 *           label sits four bytes late at 0x020934D0.  Wants a seed at
 *           0x020934CC and the 0x020934D0 label removed.  Callees:
 *           __dtoa = __num2dec, round_decimal = round_decimal,
 *           0x0209B9A0 = the runtime double `<` (__dcmp_4).  isupper() is
 *           an INLINE FUNCTION over __ctype_map, not a macro: as a macro
 *           its 0 arm is CSE'd with the 0.0 argument of `num < 0` and kept
 *           in r4 across the call (8 bytes short).  The inf/nan strcpy's
 *           are mwcc's __memcpy intrinsic from non-const char[N] externs
 *           (see double2hex.c).  radix_marker is the constant '.'.
 */
unsigned char *float2str(double num, unsigned char *buff, print_format format)
{
    decimal dec;
    decform form;
    unsigned char *p;
    unsigned char *q;
    int n, digits, sign;
    int int_digits, frac_digits;

    if (format.precision > 509)
        return 0;

    form.style = 0;
    form.digits = 0x20;
    __dtoa(&form, num, &dec);

    p = dec.sig.text + dec.sig.length;
    while (dec.sig.length > 1 && *--p == '0') {
        --dec.sig.length;
        ++dec.exp;
    }

    switch (dec.sig.text[0]) {
    case '0':
        dec.exp = 0;
        break;
    case 'I':
        if (num < 0) {
            p = buff - 5;
            if (isupper(format.conversion_char))
                __memcpy(p, sMslNegInf, 5);
            else
                __memcpy(p, sMslNegInfLower, 5);
        } else {
            p = buff - 4;
            if (isupper(format.conversion_char))
                __memcpy(p, sMslPosInf, 4);
            else
                __memcpy(p, sMslPosInfLower, 4);
        }
        return p;
    case 'N':
        if (dec.sgn) {
            p = buff - 5;
            if (isupper(format.conversion_char))
                __memcpy(p, sMslNegNan, 5);
            else
                __memcpy(p, sMslNegNanLower, 5);
        } else {
            p = buff - 4;
            if (isupper(format.conversion_char))
                __memcpy(p, sMslPosNan, 4);
            else
                __memcpy(p, sMslPosNanLower, 4);
        }
        return p;
    }

    dec.exp += dec.sig.length - 1;

    p = buff;
    *--p = 0;

    switch (format.conversion_char) {
    case 'g':
    case 'G':
        if (dec.sig.length > format.precision)
            round_decimal((Ctr *)&dec, format.precision);

        if (dec.exp < -4 || dec.exp >= format.precision) {
            if (format.alternate_form)
                --format.precision;
            else
                format.precision = dec.sig.length - 1;

            if (format.conversion_char == 'g')
                format.conversion_char = 'e';
            else
                format.conversion_char = 'E';

            goto e_format;
        }

        if (format.alternate_form)
            format.precision -= dec.exp + 1;
        else if ((format.precision = dec.sig.length - (dec.exp + 1)) < 0)
            format.precision = 0;

        goto f_format;

    case 'e':
    case 'E':
    e_format:
        if (dec.sig.length > format.precision + 1)
            round_decimal((Ctr *)&dec, format.precision + 1);

        n = dec.exp;
        sign = '+';
        if (n < 0) {
            n = -n;
            sign = '-';
        }

        for (digits = 0; n || digits < 2; ++digits) {
            *--p = n % 10 + '0';
            n /= 10;
        }

        *--p = sign;
        *--p = format.conversion_char;

        if (buff - p + format.precision > 509)
            return 0;

        if (dec.sig.length < format.precision + 1)
            for (n = format.precision + 2 - dec.sig.length; --n;)
                *--p = '0';

        for (n = dec.sig.length, q = dec.sig.text + dec.sig.length; --n;)
            *--p = *--q;

        if (format.precision || format.alternate_form)
            *--p = '.';

        *--p = dec.sig.text[0];

        if (dec.sgn)
            *--p = '-';
        else if (format.sign_options == 1)
            *--p = '+';
        else if (format.sign_options == 2)
            *--p = ' ';
        break;

    case 'f':
    case 'F':
    f_format:
        if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0)
            frac_digits = 0;

        if (frac_digits > format.precision) {
            round_decimal((Ctr *)&dec, dec.sig.length - (frac_digits - format.precision));
            if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0)
                frac_digits = 0;
        }

        if ((int_digits = dec.exp + 1) < 0)
            int_digits = 0;

        if (int_digits + frac_digits > 509)
            return 0;

        q = dec.sig.text + dec.sig.length;

        for (digits = 0; digits < (format.precision - frac_digits); ++digits)
            *--p = '0';

        for (digits = 0; digits < frac_digits && digits < dec.sig.length; ++digits)
            *--p = *--q;

        for (; digits < frac_digits; ++digits)
            *--p = '0';

        if (format.precision || format.alternate_form)
            *--p = '.';

        if (int_digits) {
            for (digits = 0; digits < int_digits - dec.sig.length; ++digits)
                *--p = '0';
            for (; digits < int_digits; ++digits)
                *--p = *--q;
        } else
            *--p = '0';

        if (dec.sgn)
            *--p = '-';
        else if (format.sign_options == 1)
            *--p = '+';
        else if (format.sign_options == 2)
            *--p = ' ';
        break;
    }

    return p;
}



/*
 * note:     MSL printf.c `__pformatter`, the vfprintf core.  REAL entry:
 *           0x02093BDC is the home-area push {r0,r1,r2,r3} (forced by &arg);
 *           the listing label sits four bytes late at 0x02093BE0 (the star).
 *           Signature (WriteProc, WriteProcArg, format_str, va_list arg,
 *           int is_secure); is_secure is the stack word [sp,#0x260].
 *           Shape levers that were load-bearing: every char is unsigned
 *           (ldrb, not ldrsb); the argument_options enum has the C99 cases
 *           6 = intmax_t (long long) and 8 = ptrdiff_t, each with its own
 *           va_arg arm; an explicit `case 0xFF:` beside `default:` (it is
 *           what makes the conversion switch a two-level range tree with
 *           the 'A'..'G' and 'd'..'x' jump tables); `%s` with L"" (wide)
 *           first, so the pool order is 0x020A8A70 (L"") then 0x020A8A74
 *           ("") -- the NARROW empty string is at 0x020A8A74, not 0x70.
 */
int __pformatter(void *(*WriteProc)(void *, const uchar *, size_t), void *WriteProcArg,
                  const uchar *format_str, va_list arg, int is_secure)
{
    int num_chars, chars_written, field_width;
    const uchar *format_ptr;
    const uchar *curr_format;
    print_format format;
    long long_num;
    long long long_long_num;
    long double long_double_num;
    uchar buff[512];
    uchar *buff_ptr;
    uchar *string_end;
    uchar fill_char = ' ';

    format_ptr = format_str;
    chars_written = 0;

    while (*format_ptr) {
        if (!(curr_format = strchr(format_ptr, '%'))) {
            num_chars = strlen(format_ptr);
            chars_written += num_chars;
            if (num_chars && !(*WriteProc)(WriteProcArg, format_ptr, num_chars))
                return -1;
            break;
        }

        num_chars = curr_format - format_ptr;
        chars_written += num_chars;
        if (num_chars && !(*WriteProc)(WriteProcArg, format_ptr, num_chars))
            return -1;

        format_ptr = curr_format;
        format_ptr = parse_format(format_ptr, &arg, &format);

        switch (format.conversion_char) {
        case 'd':
        case 'i':
            if (format.argument_options == 3)
                long_num = va_arg(arg, long);
            else if (format.argument_options == 4)
                long_long_num = va_arg(arg, long long);
            else if (format.argument_options == 6)
                long_long_num = va_arg(arg, intmax_t);
            else if (format.argument_options == 7)
                long_num = va_arg(arg, size_t);
            else if (format.argument_options == 8)
                long_num = va_arg(arg, ptrdiff_t);
            else
                long_num = va_arg(arg, int);

            if (format.argument_options == 2)
                long_num = (short)long_num;
            if (format.argument_options == 1)
                long_num = (signed char)long_num;

            if (format.argument_options == 4 || format.argument_options == 6) {
                if (!(buff_ptr = longlong2str(long_long_num, buff + 512, format)))
                    goto conversion_error;
            } else {
                if (!(buff_ptr = long2str(long_num, buff + 512, format)))
                    goto conversion_error;
            }
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (format.argument_options == 3)
                long_num = va_arg(arg, unsigned long);
            else if (format.argument_options == 4)
                long_long_num = va_arg(arg, long long);
            else if (format.argument_options == 6)
                long_long_num = va_arg(arg, intmax_t);
            else if (format.argument_options == 7)
                long_num = va_arg(arg, size_t);
            else if (format.argument_options == 8)
                long_num = va_arg(arg, ptrdiff_t);
            else
                long_num = va_arg(arg, unsigned int);

            if (format.argument_options == 2)
                long_num = (unsigned short)long_num;
            if (format.argument_options == 1)
                long_num = (unsigned char)long_num;

            if (format.argument_options == 4 || format.argument_options == 6) {
                if (!(buff_ptr = longlong2str(long_long_num, buff + 512, format)))
                    goto conversion_error;
            } else {
                if (!(buff_ptr = long2str(long_num, buff + 512, format)))
                    goto conversion_error;
            }
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'f':
        case 'F':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            if (format.argument_options == 9)
                long_double_num = va_arg(arg, long double);
            else
                long_double_num = va_arg(arg, double);
            if (!(buff_ptr = float2str(long_double_num, buff + 512, format)))
                goto conversion_error;
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'a':
        case 'A':
            if (format.argument_options == 9)
                long_double_num = va_arg(arg, long double);
            else
                long_double_num = va_arg(arg, double);
            if (!(buff_ptr = double2hex(long_double_num, buff + 512, format)))
                goto conversion_error;
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 's':
            if (format.argument_options == 5) {
                wchar_t *wcs_ptr = va_arg(arg, wchar_t *);
                if (is_secure && wcs_ptr == 0) {
                    MSL_C_LIB_CallExitHook(0, 0, -1);
                    return -1;
                }
                if (wcs_ptr == 0)
                    wcs_ptr = sMslWideEmpty;
                if ((num_chars = MSL_C_LIB_WideToNarrow(buff, wcs_ptr, sizeof(buff))) < 0)
                    goto conversion_error;
                buff_ptr = &buff[0];
            } else
                buff_ptr = va_arg(arg, uchar *);

            if (is_secure && buff_ptr == 0) {
                MSL_C_LIB_CallExitHook(0, 0, -1);
                return -1;
            }
            if (buff_ptr == 0)
                buff_ptr = sMslNarrowEmpty;

            if (format.alternate_form) {
                num_chars = (unsigned char)*buff_ptr++;
                if (format.precision_specified && num_chars > format.precision)
                    num_chars = format.precision;
            } else if (format.precision_specified) {
                num_chars = format.precision;
                if ((string_end = (uchar *)memchr(buff_ptr, 0, num_chars)) != 0)
                    num_chars = string_end - buff_ptr;
            } else
                num_chars = strlen(buff_ptr);
            break;

        case 'n':
            buff_ptr = va_arg(arg, uchar *);
            if (is_secure) {
                MSL_C_LIB_CallExitHook(0, 0, -1);
                return -1;
            }
            switch (format.argument_options) {
            case 0: *(int *)buff_ptr = chars_written; break;
            case 2: *(short *)buff_ptr = chars_written; break;
            case 3: *(long *)buff_ptr = chars_written; break;
            case 6: *(intmax_t *)buff_ptr = chars_written; break;
            case 7: *(size_t *)buff_ptr = chars_written; break;
            case 8: *(ptrdiff_t *)buff_ptr = chars_written; break;
            case 4: *(long long *)buff_ptr = chars_written; break;
            }
            continue;

        case 'c':
            buff_ptr = buff;
            *buff_ptr = va_arg(arg, int);
            num_chars = 1;
            break;

        case '%':
            buff_ptr = buff;
            *buff_ptr = '%';
            num_chars = 1;
            break;

        case 0xFF:
        default:
        conversion_error:
            num_chars = strlen(curr_format);
            chars_written += num_chars;
            if (num_chars && !(*WriteProc)(WriteProcArg, curr_format, num_chars))
                return -1;
            return chars_written;
        }

        field_width = num_chars;

        if (format.justification_options != 0) {
            fill_char = (format.justification_options == 2) ? '0' : ' ';
            if (((*buff_ptr == '+') || (*buff_ptr == '-') || (*buff_ptr == ' ')) && (fill_char == '0')) {
                if ((*WriteProc)(WriteProcArg, buff_ptr, 1) == 0)
                    return -1;
                ++buff_ptr;
                num_chars--;
            }
            if ((format.justification_options == 2) && ((format.conversion_char == 'a') || (format.conversion_char == 'A'))) {
                if (num_chars < 2)
                    return -1;
                if ((*WriteProc)(WriteProcArg, buff_ptr, 2) == 0)
                    return -1;
                num_chars -= 2;
                buff_ptr += 2;
            }
            while (field_width < format.field_width) {
                if ((*WriteProc)(WriteProcArg, &fill_char, 1) == 0)
                    return -1;
                ++field_width;
            }
        }

        if (num_chars && !(*WriteProc)(WriteProcArg, buff_ptr, num_chars))
            return -1;

        if (format.justification_options == 0)
            while (field_width < format.field_width) {
                uchar blank = ' ';
                if ((*WriteProc)(WriteProcArg, &blank, 1) == 0)
                    return -1;
                ++field_width;
            }

        chars_written += field_width;
    }

    return chars_written;
}



u32 MSL_C_LIB_SprintfWriteProc(u8 *sb, const void *src, u32 n)
{
    u32 pos = ((MslStringBuf *)sb)->length;
    u32 cap = ((MslStringBuf *)sb)->capacity;

    if (pos + n > cap)
        n = cap - pos;
    func_02092344(*(u8 * *)&((MslStringBuf *)sb)->buf + pos, src, n);
    ((MslStringBuf *)sb)->length += n;
    return 1;
}



/*
 *           That address is the home-area `push {r0,r1,r2,r3}` start of
 *           the function disasm.py labels at 0x02093BE0 (worklist pkt_020933B8,
 *           size 4); four bytes of caller-save home area cannot be produced
 *           from C, so no source file can ever earn the shard entry that
 *           would attest it.  The other site (MSL_C_LIB_SprintfWriteProc) resolved as
 *           `matched` once this packet's own shard was written.
 */
u32 vsnprintf(u8 *dst, u32 n, const u8 *format, u8 *ap)
{
    u32 state[3];
    u32 len;

    state[0] = (u32)dst;
    state[1] = n;
    state[2] = 0;
    len = __pformatter((void *(*)(void *, const uchar *, size_t))MSL_C_LIB_SprintfWriteProc, state, format, ap, 0);
    if (dst == 0)
        return len;
    if (len < n) {
        dst[len] = 0;
        return len;
    }
    if (n != 0)
        *(u8 *)((char *)dst + n - 1) = 0;
    return len;
}



/*
 * note:     this is the REAL start of the function the worklist and the
 *           listing label at 0x02094534: the first instruction is the
 *           argument home area `push {r0,r1,r2,r3}`, which saves no lr, so
 *           disasm.py put its label four bytes late.  Wants a seed at
 *           0x02094530 in layout/function_starts.txt and the label at
 *           0x02094534 removed.
 *
 *           in this packet because its own `bl 0x02093BDC` site cannot be
 *           attested), so the single call site here stays wildcarded.  The C
 *           itself is byte-correct: 36 bytes, home push included.
 */
u32 sprintf(char *dst, u32 fmt, ...)
{
    u32 *p = (u32 *)((u32)&fmt & ~3u);

    return vsnprintf((u8 *)dst, 0xFFFFFFFFu, (const u8 *)fmt, (u8 *)(p + 1));
}



/*
 * note:     MSL stdlib qsort.c `qsort` (heapsort), 312 bytes, the real open
 *           code of worklist row pkt_02094534 (0x02094534..0x0209455C is the
 *           tail of sprintf, already EXACT as src/matched/sprintf.c).
 *           disasm.py has NO label at 0x0209455C (the listing folds
 *           0x02094534..0x02094750 into one block), so the worklist counts
 *           these 312 bytes as data-adjacent extent, not code: integrator,
 *           seed 0x0209455C in layout/function_starts.txt.  Levers: the
 *           swap macro's count is assigned before its two pointers (sets
 *           the mov r2 / ldr r4 / ldr r3 order) and the bytes are unsigned
 *           char (ldrb, MSL is char-unsigned).  Verified with
 *             python3 tools/match.py one --src src/matched/qsort.c \
 *                 --func qsort --addr 0x0209455C --arm
 */
void qsort(void *table_base, size_t num_members, size_t member_size,
                   _compare_function compare_members)
{
    size_t l, r, j;
    char *lp;
    char *rp;
    char *ip;
    char *jp;
    char *kp;

    if (num_members < 2)
        return;

    r = num_members;
    l = (r / 2) + 1;

    lp = table_ptr(l);
    rp = table_ptr(r);

    for (;;) {
        if (l > 1) {
            l--;
            lp -= member_size;
        } else {
            swap(lp, rp, member_size);

            if (--r == 1)
                return;

            rp -= member_size;
        }

        j = l;

        jp = table_ptr(j);

        while (j * 2 <= r) {
            j *= 2;

            ip = jp;
            jp = table_ptr(j);

            if (j < r) {
                kp = jp + member_size;

                if (compare_members(jp, kp) < 0) {
                    j++;
                    jp = kp;
                }
            }

            if (compare_members(ip, jp) < 0)
                swap(ip, jp, member_size);
            else
                break;
        }
    }
}



u32 func_02094694(void)
{
    MslRandSeed = MslRandSeed * 0x41C64E6Du + 0x3039u;
    return (MslRandSeed >> 16) & 0x7FFFu;
}



void srand(u32 v)
{
    MslRandSeed = v;
}



int MSL_C_LIB_StrReadProc(u32 *state, u32 ch, u32 mode)
{
    switch (mode) {
    case 0: {
        u8 *q = (u8 *)*state;
        u8 c = *q;

        if (c == 0) {
            state[1] = 1;
            return -1;
        }
        *state = (u32)(q + 1);
        return c;
    }
    case 1:
        if (state[1] == 0)
            state[0] = state[0] - 1;
        else
            state[1] = 0;
        return (int)ch;
    case 2:
        return (int)state[1];
    default:
        return 0;
    }
}



/*
 * Calls the hook stored at 0x02153FB0 when it is set, otherwise falls through
 * to the default handler at 0x02094778.
 *
 * The hook is taken as a three-argument pointer because that is the only thing
 * that reproduces the original's `ldr r3` / `blx r3`: with a zero- or
 * one-argument callee the compiler puts the target in r0 or r1 and the head of
 * the function shifts.  The arguments are passed straight through, so nothing
 * in the bytes fixes their values.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_CallExitHook.c \
 *       --func MSL_C_LIB_CallExitHook --addr 0x02094750 --cc 1.1p1 --arm
 */
void MSL_C_LIB_CallExitHook(u32 a, u32 b, u32 c)
{
    if (gMslExitHook != 0) {
        gMslExitHook(a, b, c);
    } else {
        MSL_C_LIB_DefaultExitHook();
    }
}



void MSL_C_LIB_DefaultExitHook(void){ }



/*
 * A plain byte-string length counter (strlen over a u8 buffer, not the C
 * library helper): count bytes up to and including the NUL, then return the
 * count minus one.  Self-contained, no external symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strlen.c \
 *       --func strlen --addr 0x0209477C --cc 1.1p1 --arm
 */
int strlen(const u8 *s)
{
    int n = -1;

    do {
        n++;
    } while (*s++ != 0);

    return n;
}



/*
 * MSL strcpy, the 4-byte-at-a-time form (MSL_C string.c).  If source and
 * destination share a 4-byte alignment, copy the (3 - align) leading bytes,
 * then whole words while the Mycroft null-byte test
 * (w + 0xFEFEFEFF) & ~w & 0x80808080 is clear (both constants are plain pool
 * words, no relocation), and finish byte by byte from the word that carries
 * the terminator.  A misaligned pair goes to the byte loop directly.
 *
 * HOW THE 2-BYTE WALL WAS CLOSED (wave 17).  docs/notes/pkt_02094798.c.txt
 * held this at 198/200 with the loop test's `and` accumulating into the
 * register holding w + K1 instead of the one holding ~w.  Every expression
 * spelling of the test left that choice alone.  MSL spells the test as three
 * statements on one mask local, `t = w + K1; t &= ~w; t &= K2;`, in both the
 * pre-loop and the loop test, and leaves the loop with `if (t) goto adjust`
 * inside `do { } while (1)`.  That source is EXACT under 1.1p1 and 1.2.
 */
char *strcpy(char *dst, const char *src)
{
    u8 *destb;
    u8 *fromb;
    u32 w;
    u32 t;
    u32 align;

    fromb = (u8 *)src;
    destb = (u8 *)dst;

    if ((align = ((int)fromb & 3)) != ((int)destb & 3)) {
        goto bytecopy;
    }

    if (align) {
        if ((*destb = *fromb) == 0) {
            return dst;
        }
        for (align = 3 - align; align; align--) {
            if ((*(++destb) = *(++fromb)) == 0) {
                return dst;
            }
        }
        ++destb;
        ++fromb;
    }

    w = *(u32 *)fromb;
    t = w + K1;
    t &= ~w;
    t &= K2;
    if (t) {
        goto bytecopy;
    }
    destb -= 4;
    do {
        destb += 4;
        *(u32 *)destb = w;
        fromb += 4;
        w = *(u32 *)fromb;
        t = w + K1;
        t &= ~w;
        t &= K2;
        if (t) {
            goto adjust;
        }
    } while (1);

adjust:
    destb += 4;
bytecopy:
    if ((*destb = *fromb) == 0) {
        return dst;
    }
    do {
        if ((*(++destb) = *(++fromb)) == 0) {
            return dst;
        }
    } while (1);
    return dst;
}



/*
 * strncpy and strcat implementations in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02094860.c \
 *       --addr 0x02094860 --arm --cc 1.1p1
 */
u8 *strncpy(u8 *dest, const u8 *src, u32 n)
{
    u8 *d = dest;

    if (n == 0) {
        return dest;
    }

    do {
        u8 *prev = d;
        *d++ = *src++;
        if (*prev == 0) {
            if (--n == 0) {
                return dest;
            }
            do {
                *d++ = 0;
            } while (--n != 0);
            return dest;
        }

        if (--n == 0) {
            return dest;
        }
    } while (1);
}



u8 *strcat(u8 *dest, const u8 *src)
{
    u8 *d = dest;

    while (*d++)
        ;
    --d;
    while (*d++ = *src++)
        ;

    return dest;
}



/*
 * MSL strcmp, the 4-byte-at-a-time form.  Compare the first byte; if the two
 * pointers share a 4-byte alignment, copy the (3 - align) leading bytes one at
 * a time, then compare whole words using the Alan Mycroft null-byte test
 * (w + 0xFEFEFEFF) & ~w & 0x80808080 -- the two constants are the pool words at
 * 0x020949EC and 0x020949F0 and carry no relocation -- and fall into a
 * byte-by-byte epilogue at the word that carries the terminator.  A misaligned
 * pair, and a word mismatch, both enter that epilogue directly.
 *
 * HOW THE 2026-09-21 WALL WAS CLOSED.  docs/notes/strcmp.c.txt records
 * this as a 28-of-276-byte near miss "solely in register allocation between
 * r2, r4 and lr" (and that note's own source did not compile: it says
 * `(const u32 *)p2` for `s2`).  Two separate things were wrong, and both are
 * readable off the image:
 *
 *   1. ONE VARIABLE HOLDS BOTH THE WORD AND THE BYTE.  The image branches out
 *      of the word loop with `b #0x20949bc`, landing on `cmp r2, #0` -- and r2
 *      at that point holds the 32-bit WORD w1 just loaded by
 *      `ldr r2,[r0,#4]!`, not a byte.  That is sound (the haszero test has
 *      already proved no byte of the word is zero) and it is only expressible
 *      if the same `u32` names both.  Declaring a separate `unsigned char c1`
 *      for the byte adds a third value live across the word loop and widens
 *      the prologue to `push {r3, r4, r5, lr}` -- the documented symptom, and
 *      the whole 28-byte residue.
 *   2. THE FALL-THROUGH FROM find_in_word.  The image's find_in_word block at
 *      0x020949A8 ends with `popne {r4, pc}` and FALLS THROUGH into the
 *      epilogue's `cmp r2, #0`; the two `goto byte_loop` paths branch to that
 *      `cmp` instead.  Spelling the epilogue's first test as a fresh
 *      `*(const u8 *)s1 == 0` re-loads the byte and costs four bytes.
 *
 * Note the ASYMMETRY of the two haszero tests, which is in the image and is
 * not a transcription slip: the PRE-loop test at +0x74 is the full
 * `(w + C) & ~w & M` (three instructions, `mvn`/`add`/`and` then `tst`), while
 * the test INSIDE the loop at +0xA8 is only `(w + C) & M` -- `add lr,r2,r3` /
 * `tst lr,ip`, with no `mvn`.  Writing the full expression in both places
 * compiles the loop body two instructions long.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/strcmp.c \
 *       --func strcmp --addr 0x020948E0 --cc 1.1p1 --arm
 */
int strcmp(const char *s1, const char *s2)
{
    int diff;
    u32 align;
    u32 w1;
    u32 w2;

    w1 = *(const u8 *)s1;
    diff = w1 - *(const u8 *)s2;
    if (diff != 0) {
        return diff;
    }

    align = (u32)s1 & 3;
    if (((u32)s2 & 3) != align) {
        goto byte_loop;
    }

    if (align != 0) {
        if (w1 == 0) {
            return 0;
        }
        align = 3 - align;
        if (align != 0) {
            do {
                w1 = *(const u8 *)++s1;
                diff = w1 - *(const u8 *)++s2;
                if (diff != 0) {
                    return diff;
                }
                if (w1 == 0) {
                    return 0;
                }
            } while (--align != 0);
        }
        s1++;
        s2++;
    }

    w1 = *(const u32 *)s1;
    w2 = *(const u32 *)s2;
    if ((((w1 + 0xfefefeff) & ~w1) & 0x80808080) != 0) {
        goto find_in_word;
    }
    if (w1 != w2) {
        goto mismatch_word;
    }

    do {
        w1 = *(const u32 *)(s1 += 4);
        w2 = *(const u32 *)(s2 += 4);
        if (((w1 + 0xfefefeff) & 0x80808080) != 0) {
            goto find_in_word;
        }
    } while (w1 == w2);

mismatch_word:
    s1--;
    s2--;
    goto byte_loop;

find_in_word:
    w1 = *(const u8 *)s1;
    diff = w1 - *(const u8 *)s2;
    if (diff != 0) {
        return diff;
    }

byte_loop:
    if (w1 == 0) {
        return 0;
    }
    do {
        w1 = *(const u8 *)++s1;
        diff = w1 - *(const u8 *)++s2;
        if (diff != 0) {
            return diff;
        }
    } while (w1 != 0);

    return 0;
}



/*
 * strncmp and strchr implementations in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020949F4.c \
 *       --addr 0x020949F4 --arm --cc 1.1p1
 */
int strncmp(const u8 *s1, const u8 *s2, u32 n)
{
    if (n != 0) {
        do {
            u8 c2 = *s2++;
            u8 c1 = *s1++;
            if (c1 != c2) {
                return c1 - c2;
            }
            if (c1 == 0) {
                break;
            }
        } while (--n != 0);
    }

    return 0;
}



u8 *strchr(const u8 *s, int c)
{
    u8 m = (u8)c;
    u8 ch;

    ch = *s++;
    while (ch != 0) {
        if (ch == m)
            return (u8 *)s - 1;
        ch = *s++;
    }
    return m ? 0 : (u8 *)s - 1;
}



/*
 * strcspn, in the MSL string module this pseudo-family is made of
 * (strncmp strncmp, strchr strchr, strstr strstr).
 * Builds a 32-byte bitmap of the reject set on the stack, then scans the
 * subject until a member is hit, returning the index of that byte.
 *
 * TWO SPELLINGS ARE LOAD-BEARING, and both were missed by the two earlier
 * lanes recorded in docs/notes/strcspn.c.txt and
 * docs/notes/pkt_02094A60.c.txt, which between them left this at
 * DIFF / 188 bytes against 192 / 124 concrete bytes out:
 *
 *  - The character is `int c`, NOT `u8 c`.  The original masks it with a
 *    separate `and ip, r4, #0xff` whose result lives across the pointer
 *    load and indexes the map as `ldrb r3, [lr, ip, asr #3]` -- an
 *    ARITHMETIC shift, which is what an `int` shift compiles to.  With
 *    `u8 c` the cast is a no-op, the mask disappears, the map index folds
 *    into the load and the function loses four bytes and a saved register
 *    (`push {r4, lr}` for the original's `push {r3, r4, r5, lr}`).  This
 *    one change alone takes the body from 124 concrete bytes out to 10,
 *    size-exact, with every byte from +0x30 to the epilogue identical.
 *
 *  - The clear loop's COUNTER must be declared BEFORE the cursor
 *    (`u32 i = 8;` then `u8 *p = map;`).  This is
 *    docs/idioms/declaration-order-decides-which-register-a-local-gets.md:
 *    the original puts the cursor in ip and the counter in r3
 *    (`add ip, sp, #0` / `mov r3, #8` / ... / `subs r3, r3, #1`), and the
 *    reverse declaration order hands them the opposite pair, the residual
 *    10 bytes.  `int i` instead of `u32 i` is 160 bytes out: the signed
 *    counter costs a separate `cmp`/`bgt` in place of `subs`/`bne`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strcspn.c \
 *       --func strcspn --addr 0x02094A60 --cc 1.1p1 --arm
 *   EXACT, 192 bytes, no relocation sites.
 */
int strcspn(const u8 *s, const u8 *reject)
{
    u8 map[32];
    u32 i = 8;
    u8 *p = map;
    int c;
    const u8 *p_reject;
    const u8 *p_s;

    do {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    } while (--i);

    c = *reject;
    p_reject = reject + 1;

    if (c != 0) {
        do {
            map[(u8)c >> 3] |= (u8)(1 << (c & 7));
            c = *p_reject++;
        } while (c != 0);
    }

    c = *s;
    p_s = s + 1;

    if (c != 0) {
        do {
            if (map[(u8)c >> 3] & (u8)(1 << (c & 7))) {
                break;
            }
            c = *p_s++;
        } while (c != 0);
    }

    return (u32)(p_s - s) - 1;
}



/*
 * strstr implementation in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strstr.c \
 *       --func strstr --addr 0x02094B20 --cc 1.1p1 --arm
 */
u8 *strstr(const u8 *s1, const u8 *s2)
{
    u8 c2;
    u8 c1;
    const u8 *p;

    if (s2 == 0 || (c2 = *s2) == 0) {
        return (u8 *)s1;
    }

    c1 = *s1;
    p = s1 + 1;

    if (c1 != 0) {
        do {
            if (c1 == c2) {
                const u8 *p2 = s2 + 1;
                const u8 *p1 = p;
                u8 sc2, sc1;

                do {
                    sc2 = *p2++;
                    sc1 = *p1++;
                    if (sc1 != sc2) {
                        break;
                    }
                } while (sc1 != 0);

                if (sc2 == 0) {
                    return (u8 *)p - 1;
                }
            }
            c1 = *p++;
        } while (c1 != 0);
    }

    return 0;
}



#undef isdigit


#undef isdigit

#undef isdigit
#define isdigit(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))



#define final_state(s) ((s) & (finished | failure))


#define success(s) ((s) & (leading_sig_zeroes | int_digit_loop | frac_digit_loop | \
                           leading_exp_zeroes | exp_digit_loop | finished))



/*
 * MSL __strtold (C99 soft-float number scanner, decimal and hex paths).
 *
 * EXACT, 3864 bytes against 3864, 17 of 17 relocation sites resolved
 * (match.py one, 1.1p1 -O4,p, 2026-09-24, wave 21 lane A).
 *
 * What closed the MATCH cap: the two local model arrays.  MSL writes them
 * as `unsigned char model[] = "INFINITY";` and `... = "NAN(";`, which makes
 * the compiler emit anonymous string literals (@52/@70) into the object's
 * own .rodata; those two ABS32 pool words (+0x0EF0, +0x0EF4) had no name
 * and no witness.  Here each array is a one-member struct copied from an
 * extern pinned to the address the image's pool word names (0x020A62E4
 * "INFINITY", 0x020A62DC "NAN("), the same treatment as a __FILE__ string
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).  The
 * struct copy is byte-identical to the literal initialiser (same 4x2-byte
 * copy loop plus tail byte, same unrolled 5-byte copy).  s_infinity attests
 * by `string`, s_nan and __double_huge by sole-ref.
 *
 * Register colouring of the hex tail: the hex block declares hexresult,
 * ui2, ch2, p, hch in that order (wave 20 lane 20M); see
 * docs/idioms/declaration-position-orders-block-scope-colouring.md and
 * docs/notes/pkt_02094B8C.c.txt.
 */
double __strtold(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                     int *chars_scanned, int *overflow)
{
    int scan_state = start;
    int hex_scan_state = not_hex;
    int count = 0;
    int spaces = 0;
    int c;
    decimal2 d = {0, 0, 0, {0, ""}};
    int sig_negative = 0;
    int exp_negative = 0;
    long exp_value = 0;
    int exp_adjust = 0;
    double result;
    int sign_detected = 0;
    unsigned char *chptr;
    unsigned char mantissa[8];
    unsigned char uch, uch1;
    unsigned long ui = 0;
    unsigned long chindex;
    int NibbleIndex;
    int expsign = 0;
    int exp_negsign = 0;
    unsigned intdigits = 0;
    unsigned maxdigits;

    *overflow = 0;
    c = fetch();

    while (count <= max_width && c != -1 && !final_state(scan_state))
    {
        switch (scan_state)
        {
        case start:
            if (isspace(c))
            {
                c = fetch();
                count--;
                spaces++;
                break;
            }
            switch (toupper(c))
            {
            case '-':
                sig_negative = 1;
            case '+':
                c = fetch();
                sign_detected = 1;
                break;
            case 'I':
                c = fetch();
                scan_state = infin_state;
                break;
            case 'N':
                c = fetch();
                scan_state = nan_state;
                break;
            default:
                scan_state = sig_start;
                break;
            }
            break;

        case infin_state:
        {
            int i = 1;
            model9 model = s_infinity;

            while ((i < 8) && (toupper(c) == model.c[i]))
            {
                i++;
                c = fetch();
            }
            if ((i == 3) || (i == 8))
            {
                if (sig_negative)
                    result = -INFINITY;
                else
                    result = INFINITY;
                *chars_scanned = spaces + i + sign_detected;
                return result;
            }
            else
                scan_state = failure;
            break;
        }

        case nan_state:
        {
            int i = 1, j = 0;
            model5 model = s_nan;
            char nan_arg[32] = "";

            while ((i < 4) && (toupper(c) == model.c[i]))
            {
                i++;
                c = fetch();
            }
            if ((i == 3) || (i == 4))
            {
                if (i == 4)
                {
                    while ((j < 32) && (isdigit(c) || isalpha(c) || c == '.'))
                    {
                        nan_arg[j++] = c;
                        c = fetch();
                    }
                    if (c != ')')
                    {
                        scan_state = failure;
                        break;
                    }
                    else
                        j++;
                }
                nan_arg[j] = '\0';
                if (sig_negative)
                    result = -nan(nan_arg);
                else
                    result = nan(nan_arg);
                *chars_scanned = spaces + i + j + sign_detected;
                return result;
            }
            else
                scan_state = failure;
            break;
        }

        case sig_start:
            if (c == '.')
            {
                scan_state = frac_start;
                c = fetch();
                break;
            }
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            if (c == '0')
            {
                c = fetch();
                if (toupper(c) == 'X')
                {
                    scan_state = hex_state;
                    hex_scan_state = hex_start;
                }
                else
                    scan_state = leading_sig_zeroes;
                break;
            }
            scan_state = int_digit_loop;
            break;

        case leading_sig_zeroes:
            if (c == '0')
            {
                c = fetch();
                break;
            }
            scan_state = int_digit_loop;
            break;

        case int_digit_loop:
            if (!isdigit(c))
            {
                if (c == '.')
                {
                    scan_state = frac_digit_loop;
                    c = fetch();
                }
                else
                    scan_state = sig_end;
                break;
            }
            if (d.sig.length < 20)
                d.sig.text[d.sig.length++] = c;
            else
                exp_adjust++;
            c = fetch();
            break;

        case frac_start:
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            scan_state = frac_digit_loop;
            break;

        case frac_digit_loop:
            if (!isdigit(c))
            {
                scan_state = sig_end;
                break;
            }
            if (d.sig.length < 20)
            {
                if (c != '0' || d.sig.length)
                    d.sig.text[d.sig.length++] = c;
                exp_adjust--;
            }
            c = fetch();
            break;

        case sig_end:
            if (toupper(c) == 'E')
            {
                scan_state = exp_start;
                c = fetch();
                break;
            }
            scan_state = finished;
            break;

        case exp_start:
            if (c == '+')
            {
                c = fetch();
            }
            else if (c == '-')
            {
                c = fetch();
                exp_negative = 1;
            }
            scan_state = leading_exp_digit;
            break;

        case leading_exp_digit:
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            if (c == '0')
            {
                scan_state = leading_exp_zeroes;
                c = fetch();
                break;
            }
            scan_state = exp_digit_loop;
            break;

        case leading_exp_zeroes:
            if (c == '0')
            {
                c = fetch();
                break;
            }
            scan_state = exp_digit_loop;
            break;

        case exp_digit_loop:
            if (!isdigit(c))
            {
                scan_state = finished;
                break;
            }
            exp_value = exp_value * 10 + (c - '0');
            if (exp_value > 308)
                *overflow = 1;
            c = fetch();
            break;

        case hex_state:
            switch (hex_scan_state)
            {
            case hex_start:
                chptr = (unsigned char *)&mantissa;
                intdigits = 0;
                maxdigits = 14;
                chptr[0] = 0;
                chptr[1] = 0;
                chptr[2] = 0;
                chptr[3] = 0;
                chptr[4] = 0;
                chptr[5] = 0;
                chptr[6] = 0;
                chptr[7] = 0;
                NibbleIndex = 0;
                hex_scan_state = hex_leading_sig_zeroes;
                c = fetch();
                break;

            case hex_leading_sig_zeroes:
                if (c == '0')
                {
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_int_digit_loop;
                break;

            case hex_int_digit_loop:
                if (!isxdigit(c))
                {
                    if (c == '.')
                    {
                        hex_scan_state = hex_frac_digit_loop;
                        c = fetch();
                    }
                    else
                        hex_scan_state = hex_sig_end;
                    break;
                }
                if (intdigits < maxdigits)
                {
                    intdigits++;
                    uch = chptr[NibbleIndex / 2];
                    c = toupper(c);
                    uch1 = (c >= 'A') ? c - 'A' + 10 : c - '0';
                    if (NibbleIndex % 2)
                        uch |= uch1;
                    else
                        uch |= (unsigned char)(uch1 << 4);
                    chptr[NibbleIndex++ / 2] = uch;
                    c = fetch();
                    break;
                }
                c = fetch();
                break;

            case hex_frac_digit_loop:
                if (!isxdigit(c))
                {
                    hex_scan_state = hex_sig_end;
                    break;
                }
                if (intdigits < maxdigits)
                {
                    uch = chptr[NibbleIndex / 2];
                    c = toupper(c);
                    uch1 = (c >= 'A') ? c - 'A' + 10 : c - '0';
                    if (NibbleIndex % 2)
                        uch |= uch1;
                    else
                        uch |= (unsigned char)(uch1 << 4);
                    chptr[NibbleIndex++ / 2] = uch;
                    c = fetch();
                    break;
                }
                c = fetch();
                break;

            case hex_sig_end:
                if (toupper(c) == 'P')
                {
                    hex_scan_state = hex_exp_start;
                    c = fetch();
                    break;
                }
                scan_state = finished;
                break;

            case hex_exp_start:
                if (c == '-')
                    exp_negsign = 1;
                else if (c != '+')
                {
                    unfetch(c);
                    count--;
                }
                hex_scan_state = hex_leading_exp_digit;
                c = fetch();
                break;

            case hex_leading_exp_digit:
                if (!isdigit(c))
                {
                    scan_state = failure;
                    break;
                }
                if (c == '0')
                {
                    hex_scan_state = hex_leading_exp_zeroes;
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_exp_digit_loop;
                break;

            case hex_leading_exp_zeroes:
                if (c == '0')
                {
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_exp_digit_loop;
                break;

            case hex_exp_digit_loop:
                if (!isdigit(c))
                {
                    scan_state = finished;
                    break;
                }
                expsign = expsign * 10 + (c - '0');
                if (exp_value > 0x7FFF)
                    *overflow = 1;
                c = fetch();
                break;
            }
            break;
        }
    }

    if (scan_state != hex_state ? !success(scan_state) : !hex_success(count, hex_scan_state))
    {
        count = 0;
        *chars_scanned = 0;
    }
    else
    {
        count--;
        *chars_scanned = count + spaces;
    }

    unfetch(c);

    if (hex_scan_state == not_hex)
    {
        if (exp_negative)
            exp_value = -exp_value;
        {
            int n = d.sig.length;
            unsigned char *p = &d.sig.text[n];

            while (n-- && *--p == '0')
                exp_adjust++;
            d.sig.length = n + 1;
            if (d.sig.length == 0)
                d.sig.text[d.sig.length++] = '0';
        }
        if (exp_value < -308 || exp_value > 308)
        {
            if (*overflow == 0 && d.sig.text[0] == '0' && d.sig.text[1] == 0)
                return 0.0;
            *overflow = 1;
        }
        exp_value += exp_adjust;
        if (*overflow)
        {
            if (exp_negative)
                return 0.0;
            else
                return sig_negative ? -HUGE_VAL : HUGE_VAL;
        }
        d.exp = (short)exp_value;
        result = __dec2num(&d);
        if (result != 0.0 && result < 2.2250738585072014e-308)
        {
            *overflow = 1;
        }
        else if (result > 1.7976931348623157e+308)
        {
            *overflow = 1;
            result = HUGE_VAL;
        }
        if (sig_negative && success(scan_state))
            result = -result;
        return result;
    }
    else
    {
        double hexresult;
        unsigned long ui2;
        unsigned long ch2;
        unsigned char *p = (unsigned char *)&hexresult;
        unsigned char hch;

        if (exp_negsign)
            expsign = -expsign;
        expsign += intdigits * 4;
        hch = mantissa[0];
        for (ui = 0; ui < 4 && !(hch & (0x80 >> ui)); ui++)
            expsign--;
        expsign--;
        if ((chindex = ++ui) != 0)
        {
            uch1 = 0;
            for (chptr = mantissa + 7; chptr >= mantissa; chptr--)
            {
                hch = *chptr;
                *chptr = (hch << chindex) | uch1;
                uch1 = hch >> (8 - chindex);
            }
        }
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        for (ui2 = 0, ch2 = 12; ui2 < 52; ui2 += 8)
        {
            hch = mantissa[ui2 / 8];
            if (ui2 + 8 > 52)
                hch &= 0xff << (52 - ui2);
            NibbleIndex = ch2 % 8;
            p[ch2 / 8] |= (unsigned char)(hch >> NibbleIndex);
            ch2 += 8;
            p[ch2 / 8] |= (unsigned char)(hch << (8 - NibbleIndex));
        }
        expsign += exp_value + 0x3FF;
        if (expsign & ~0x7FF)
        {
            *overflow = 1;
            return 0.0;
        }
        p[0] |= (unsigned)(expsign << 21) >> 25;
        p[1] |= (unsigned)(expsign << 21) >> 17;
        if (sig_negative)
            p[0] |= 0x80;
        for (NibbleIndex = 0; NibbleIndex < 4; NibbleIndex++)
        {
            hch = p[NibbleIndex];
            p[NibbleIndex] = p[7 - NibbleIndex];
            p[7 - NibbleIndex] = hch;
        }
        return *(double *)p;
    }
}



/*
 * PROMOTED from src/pending/ with no change to the C (lane r5c, 2026-09-19):
 * the park's only blocker was the PC24 at +0x34, and 0x02094B8C is now a
 * layout/runtime_arm9.txt entry (_msl_scanf_strtod_core), so that site
 * attests as `runtime` and every relocation resolves:
 *
 *   +0034 PC24 __strtold   -> 02094B8C  [runtime x1, e.g. 02094B8C]
 *   +0058 PC24 fabs   -> 0209A504  [label x15, e.g. 02093310]
 *   +0080 ABS32 MSL_C_LIB_StrReadProc  -> 020946D8  [literal x15, e.g. 02095F38]
 *   +0084 ABS32 errno     -> 02153FAC  [literal x35, e.g. 02091D34]
 *
 * EXACT* and not EXACT: the compiled body is 136 bytes and the listing extent
 * is 152, because the follower at 0x02095B2C is the linker stub
 * (`ldr ip,[pc,#4]; mov r1,#0; bx ip; .word 0x02095AA4`), which carries no
 * func_ label and is not producible from C, so the inferred extent runs long
 * over it.  No byte inside the compared range differs.
 */
u64 strtod(u32 s, u32 *endptr)
{
    u32 buf[4];
    u64 r;

    buf[1] = 0;
    buf[0] = s;
    r = ((u64 (*)(u32, u32, u32 *, u32 *, u32 *))__strtold)(0x7FFFFFFFu, (u32)MSL_C_LIB_StrReadProc, buf, &buf[3], &buf[2]);
    if (endptr != 0)
        *endptr = s + buf[3];
    ((void (*)(u32, u32))fabs)((u32)r, (u32)(r >> 32));
    if (buf[2] != 0)
        errno = 0x22;
    return r;
}



/*
 * sdk:      FATFS_FormatDrive (libfatfs.TWL.HYB.a fatfs_api.o)
 */
int atof(char *s)
{
    return strtod((u32)s, 0);
}


#undef isdigit

#undef isdigit

#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))



enum { dec_start = 1, check_for_zero = 2, leading_zero = 4, need_digit = 8,
       digit_loop = 16, dec_finished = 32, dec_failure = 64 };



#undef final_state


#undef final_state

#undef final_state
#define final_state(s) ((s) & (dec_finished | dec_failure))



#undef success


#undef success

#undef success
#define success(s)     ((s) & (leading_zero | digit_loop | dec_finished))



/*
 * MSL __strtoul: the scan-state machine every strtol/strtoul/atoi entry
 * drives (strtoul and strtol are two of its wrappers).  The
 * source is the Metrowerks one nearly verbatim: the power-of-two scan
 * states (start 1 .. failure 0x40, `tst #0x60` = final_state, `tst #0x34`
 * = success), fetch() as `(count++, ReadProc(arg, 0, 0))` and unfetch as
 * `ReadProc(arg, c, 1)`, the `c = fetch(); count--; spaces++;` whitespace
 * skip, and the <ctype.h> macros written as `(c < 0 || c >= 0x80) ? 0 :
 * __ctype_map[c] & bit` -- mwcc folds that pair of signed tests into the
 * image's single unsigned `cmp #0x80 / movhs`.  Bits: 0x100 space, 8 digit,
 * 1 alpha; __upper_map is the 128-byte toupper table sitting directly below
 * __ctype_map.  EOF and ULONG_MAX share the one `mvn fp, #0` register.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__strtoul.c \
 *       --func __strtoul --addr 0x02095B3C --cc 1.1p1 --arm
 *   EXACT, 880 bytes, 4 relocation sites, all resolved.
 */
u32 __strtoul(int base, int max_width, int (*ReadProc)(void *, int, int),
                  void *ReadProcArg, int *chars_scanned, int *negative,
                  int *overflow)
{
    int scan_state = dec_start;
    int count = 0;
    int spaces = 0;
    u32 value = 0;
    u32 value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1)
        scan_state = dec_failure;
    else
        c = fetch();

    if (base != 0)
        value_max = 0xFFFFFFFFu / base;

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
        case dec_start:
            if (isspace(c)) {
                c = fetch();
                count--;
                spaces++;
                break;
            }
            if (c == '+') {
                c = fetch();
            } else if (c == '-') {
                c = fetch();
                *negative = 1;
            }
            scan_state = check_for_zero;
            break;
        case check_for_zero:
            if (base == 0 || base == 16) {
                if (c == '0') {
                    scan_state = leading_zero;
                    c = fetch();
                    break;
                }
            }
            scan_state = need_digit;
            break;
        case leading_zero:
            if (c == 'X' || c == 'x') {
                base = 16;
                scan_state = need_digit;
                c = fetch();
                break;
            }
            if (base == 0)
                base = 8;
            scan_state = digit_loop;
            break;
        case need_digit:
        case digit_loop:
            if (base == 0)
                base = 10;
            if (!value_max)
                value_max = 0xFFFFFFFFu / base;
            if (isdigit(c)) {
                if ((c -= '0') >= base) {
                    if (scan_state == digit_loop)
                        scan_state = dec_finished;
                    else
                        scan_state = dec_failure;
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == digit_loop)
                    scan_state = dec_finished;
                else
                    scan_state = dec_failure;
                break;
            } else {
                c = toupper(c) - 'A' + 10;
            }
            if (value > value_max)
                *overflow = 1;
            value *= base;
            if (c > (0xFFFFFFFFu - value))
                *overflow = 1;
            value += c;
            scan_state = digit_loop;
            c = fetch();
            break;
        }
    }

    if (!success(scan_state)) {
        count = value = 0;
        *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }
    unfetch(c);
    return value;
}



/*
 * MSL strtoul: the unsigned member of the strtoX wrapper family over the
 * scanner core at 0x02095B3C.  Four lanes and twenty-five spellings left this
 * at one instruction out (+0x70, `mvnne r0, #0` against 1.1p1's
 * `subne r0, r1, #0x23` fold from the 0x22 errno value) because every one of
 * them RETURNED the -1 from inside the error block.  The MSL source does not:
 *
 *     if (overflow) { value = ULONG_MAX; errno = ERANGE; }
 *     else if (negative) value = -value;
 *     return value;
 *
 * The -1 is assigned to the result variable BEFORE the errno store, the
 * negation is an ELSE-IF, and there is one return.  Under that shape the
 * value is a definition of `r` rather than a return constant and the back
 * end rematerialises it with `mvn`; the same compiler, no pin.  The return
 * type is u32 (unsigned long) and the core's return is u32 as well.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/strtoul.c \
 *       --func strtoul --addr 0x02095EAC --cc 1.1p1 --arm
 *   EXACT, 148 bytes, 3 relocation sites, all resolved.
 */
u32 strtoul(u32 s, u32 *endptr, u32 base)
{
    u32 len;
    u32 sign;
    u32 err;
    u32 buf[2];
    u32 r;

    buf[0] = s;
    buf[1] = 0;
    r = __strtoul(base, 0x7FFFFFFFu, (int (*)(void *, int,  int))((u32)MSL_C_LIB_StrReadProc), buf, (int *)(&len), (int *)(&sign), (int *)(&err));
    if (endptr != 0)
        *endptr = s + len;
    if (err != 0) {
        r = 0xFFFFFFFFu;
        errno = 0x22;
    } else if (sign != 0)
        r = -r;
    return r;
}



/*
 * The 32-bit member of the decimal-to-integer family (strtoul,
 * strtoll are its siblings and differ only in their callee and in the
 * width of the clamped result).  It runs the parser at 0x02095B3C over a
 * five-word working buffer with the sign flag 0x7FFFFFFF and the default
 * radix, stores the end-of-digits pointer through the optional out parameter,
 * and clamps the parsed magnitude to the int range: with a cleared sign a
 * magnitude above 0x7FFFFFFF does not fit and with a set sign the magnitude
 * may reach 0x80000000, after which the result is negated.
 *
 * Two things pin the source shape:
 *
 *  - The three range conditions have to be ONE disjunction.  Written as an
 *    if/else the shared error block is laid out after the final return and
 *    the whole tail shifts; as `||` the block lands exactly where the
 *    original has it, between the second range test and the negation, and
 *    the second test's branch inverts to `bls` over the error block.
 *  - The saturating values are INT_MIN for a set sign and INT_MAX for a
 *    cleared one.  mwcc materialises the pair as `movne r0, #0x80000000` /
 *    `mvneq r0, #0x80000000`, and the second is a `mvn` of 0x80000000, i.e.
 *    0x7FFFFFFF, not the same value written twice: a source whose two arms
 *    are equal is folded to a single `mov` and loses both the compare and
 *    twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strtol.c \
 *       --func strtol --addr 0x02095F40 --cc 1.1p1 --arm
 *   EXACT, 196 bytes, 3 relocation sites, all resolved.
 */
int strtol(u32 s, u32 *endptr, u32 base)
{
    u32 buf[5];
    int r;
    int v;

    buf[0] = s;
    buf[1] = 0;
    r = (int)__strtoul(base, 0x7FFFFFFFu, (int (*)(void *, int,  int))MSL_C_LIB_StrReadProc, buf,
                           (int *)(&buf[4]), (int *)(&buf[3]), (int *)(&buf[2]));
    if (endptr != 0)
        *endptr = s + buf[4];
    if (buf[2] != 0 ||
        (buf[3] == 0 && (u32)r > 0x7FFFFFFFu) ||
        (buf[3] != 0 && (u32)r > 0x80000000u)) {
        v = (buf[3] != 0) ? (int)0x80000000 : (int)0x7FFFFFFF;
        errno = 0x22;
        return v;
    }
    if (buf[3] != 0)
        r = -r;
    return r;
}


#undef isdigit

#undef isdigit

#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))



/*
 * MSL __strtoull: the 64-bit twin of src/matched/__strtoul.c (__strtoul),
 * driven by the strtoll wrapper strtoll.  Identical source with
 * `value`/`value_max` widened to unsigned long long and ULLONG_MAX in both
 * places; ULLONG_MAX / base goes through _ll_udiv with the int base
 * sign-extended (`asr r3, sb, #0x1f`), and the constant -1 lives in one stack
 * slot (sp+0x18) that serves both EOF and ULLONG_MAX.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__strtoull.c \
 *       --func __strtoull --addr 0x02096004 --cc 1.1p1 --arm
 *   EXACT, 1012 bytes, 4 relocation sites, all resolved.
 */
u64 __strtoull(int base, int max_width, int (*ReadProc)(void *, int, int),
                  void *ReadProcArg, int *chars_scanned, int *negative,
                  int *overflow)
{
    int scan_state = dec_start;
    int count = 0;
    int spaces = 0;
    u64 value = 0;
    u64 value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1)
        scan_state = dec_failure;
    else
        c = fetch();

    if (base != 0)
        value_max = 0xFFFFFFFFFFFFFFFFull / base;

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
        case dec_start:
            if (isspace(c)) {
                c = fetch();
                count--;
                spaces++;
                break;
            }
            if (c == '+') {
                c = fetch();
            } else if (c == '-') {
                c = fetch();
                *negative = 1;
            }
            scan_state = check_for_zero;
            break;
        case check_for_zero:
            if (base == 0 || base == 16) {
                if (c == '0') {
                    scan_state = leading_zero;
                    c = fetch();
                    break;
                }
            }
            scan_state = need_digit;
            break;
        case leading_zero:
            if (c == 'X' || c == 'x') {
                base = 16;
                scan_state = need_digit;
                c = fetch();
                break;
            }
            if (base == 0)
                base = 8;
            scan_state = digit_loop;
            break;
        case need_digit:
        case digit_loop:
            if (base == 0)
                base = 10;
            if (!value_max)
                value_max = 0xFFFFFFFFFFFFFFFFull / base;
            if (isdigit(c)) {
                if ((c -= '0') >= base) {
                    if (scan_state == digit_loop)
                        scan_state = dec_finished;
                    else
                        scan_state = dec_failure;
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == digit_loop)
                    scan_state = dec_finished;
                else
                    scan_state = dec_failure;
                break;
            } else {
                c = toupper(c) - 'A' + 10;
            }
            if (value > value_max)
                *overflow = 1;
            value *= base;
            if (c > (0xFFFFFFFFFFFFFFFFull - value))
                *overflow = 1;
            value += c;
            scan_state = digit_loop;
            c = fetch();
            break;
        }
    }

    if (!success(scan_state)) {
        count = value = 0;
        *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }
    unfetch(c);
    return value;
}



/*
 *           range: the only branch to it anywhere in the image is the bl in
 *           this function (it has a func_ label, but the label class needs a
 *           branch from outside the compared range as well), so that one
 *           relocation stays wildcarded and the file cannot be EXACT.  The
 *           file becomes EXACT* the day 0x02096004 gets a shard entry.
 *
 * bcd_to_s64: the 64-bit sibling of strtoul/strtol.  It hands
 * the decimal parser __strtoull a working buffer, a pointer to the first
 * byte after the parsed digits and a sign flag, then clamps the parsed
 * magnitude to the s64 range: with a zero sign a magnitude above
 * 0x7FFFFFFFFFFFFFFF does not fit, with a set sign the magnitude may reach
 * 0x8000000000000000, and the result is negated for the sign.
 *
 * The error path returns the saturating extremes of the original's own sign
 * flag, which is why the reserved word errno is set to 0x22 there.
 *
 * The bounded-magnitude test has to be one disjunction: written as an
 * if/else the shared error block is laid out after the final return and the
 * whole tail moves (66 bytes), while `||` over the three conditions places it
 * exactly where the original has it, between the second range test and the
 * negation.  The `-r` and the return then share one epilogue.
 *
 * trailing star: the listing's extent for this address runs to 0x02096508
 * because everything between the last code byte (0x020964D8) and the next
 * label is unlabelled: this function's own two-word pool at 0x020964D8 and
 * two sixteen-byte argument-defaulting thunks at 0x020964E0 and 0x020964F4
 * (`ldr ip,[pc,#8]; mov r1,#0; mov r2,#0xa; bx ip` -> 0x02095F40 and
 * 0x020963F8).  Needs seeds for both thunk addresses in
 * layout/function_starts.txt; neither is producible from C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strtoll.c \
 *       --func strtoll --addr 0x020963F8 --cc 1.1p1 --arm
 *   MATCH* with no concrete byte differing; EXACT* once the symbols above
 *   are declared and the two thunk addresses are labelled.
 */
s64 strtoll(u32 s, u32 *endptr, u32 base)
{
    u32 buf[5];
    s64 r;
    s64 v;

    buf[0] = s;
    buf[1] = 0;
    r = (s64)__strtoull(base, 0x7FFFFFFFu, (int (*)(void *, int,  int))MSL_C_LIB_StrReadProc, buf,
                           (int *)(&buf[4]), (int *)(&buf[3]), (int *)(&buf[2]));
    if (endptr != 0)
        *endptr = s + buf[4];
    if (buf[2] != 0 ||
        (buf[3] == 0 && (u64)r > 0x7FFFFFFFFFFFFFFFULL) ||
        (buf[3] != 0 && (u64)r > 0x8000000000000000ULL)) {
        v = (buf[3] != 0) ? (s64)0x8000000000000000ULL
                          : (s64)0x7FFFFFFFFFFFFFFFULL;
        errno = 0x22;
        return v;
    }
    if (buf[3] != 0)
        r = -r;
    return r;
}



/*
 * Argument-defaulting thunk: call the int decimal parser strtol with
 * a null out-pointer and radix 10.  It is the `atoi` entry point the overlay
 * error parser uses.  Reproducible from C as an ordinary tail call; the
 * previous note that claimed otherwise was wrong.
 */
int atoi(u32 s)
{
    return strtol(s, 0, 10);
}



/*
 * Argument-defaulting thunk: call the s64 decimal parser strtoll with
 * a null out-pointer and radix 10.  Reproducible from C as an ordinary tail
 * call; the previous note that claimed otherwise was wrong.
 */
long long atoll(u32 s)
{
    return strtoll(s, 0, 10);
}



/*
 * note:     the trailing star is the two unlabelled leaves that follow in the
 *           word run -- wcslen (0x02096578) and wcscpy
 *           (0x02096594), both matched in this window -- so the listing extent
 *           runs to 0x020965B4.  Wants seeds for both addresses in
 *           layout/function_starts.txt.
 */
int fwide(u8 *stream, int orientation)
{
    u32 f;

    if (stream == 0 || ((((struct MslStream *)stream)->mode << 22) >> 29) == 0)
        return 0;

    f = ((struct MslStream *)stream)->mode;
    switch ((f << 20) >> 30) {
    case 0:
        if (orientation > 0)
            ((struct MslStream *)stream)->mode = (f & ~0xc00u) | 0x800u;
        else if (orientation < 0)
            ((struct MslStream *)stream)->mode = (f & ~0xc00u) | 0x400u;
        break;
    case 1:
        orientation = -1;
        break;
    case 2:
        orientation = 1;
        break;
    }
    return orientation;
}



int wcslen(const u16 *s)
{
    int n = -1;
    u16 c;

    do {
        c = *s++;
        n++;
    } while (c != 0);
    return n;
}



/*
 * note:     the second of the two unlabelled leaves trailing fwide's
 *           word run (the first is wcslen, its own file).  It is
 *           wcslen's wide-string copy counterpart: a `do { t = p;
 *           *p = *s++; p++; } while (*t);` loop, which is what keeps the
 *           `mov ip, r3` / `ldrh r2, [ip]` re-read of the character just
 *           stored -- the store and the loop test go through two different
 *           pointer variables, so the value is not forwarded into the compare.
 */
u16 *wcscpy(u16 *d, const u16 *s)
{
    u16 *r = d;
    u16 *p = d;
    u16 *t;

    do {
        t = p;
        *p = *s++;
        p++;
    } while (*t);
    return r;
}



int MSL_C_LIB_ShouldRoundUp(u8 *dec, int idx)
{
    u8 *q = dec + 5 + idx;

    if (q[0] > 5) return 1;
    if (q[0] < 5) return -1;
    for (q++; q < dec + 5 + dec[4]; q++) {
        if (*q) return 1;
    }
    return ((dec + 5)[idx - 1] & 1) ? 1 : -1;
}



void MSL_C_LIB_IncrementDigits(u8 *dec, int idx)
{
    u8 *base = dec + 5;
    u8 *cur = base + idx - 1;

    for (;;) {
        if (*cur < 9) {
            *cur = *cur + 1;
            return;
        }
        if (cur == base) {
            *cur = 1;
            ((struct DB *)dec)->exp = ((struct DB *)dec)->exp + 1;
            return;
        }
        *cur = 0;
        cur--;
    }
}



/*
 * closed:   blocker func_020965B4 is now a manifest entry (matched class)
 *
 * Clamps the new value against the count byte at +4, records it and, when the
 * worker returns non-negative, propagates it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_SetPrecision.c \
 *       --func MSL_C_LIB_SetPrecision --addr 0x02096670 --cc 1.1p1 --arm
 */
void MSL_C_LIB_SetPrecision(DB *dec, int precision)
{
    int r;

    if (precision <= 0) {
        return;
    }
    if (precision >= dec->length) {
        return;
    }
    r = func_020965B4((u8 *)dec, precision);
    dec->length = precision;
    if (r < 0) {
        return;
    }
    MSL_C_LIB_IncrementDigits((u8 *)dec, precision);
}



/*
 * MSL __ull2dec: unsigned long long -> decimal record (struct Bcd / DB in the
 * cluster headers, MSL's `decimal`).  Four lanes and ~2800 permuter compiles
 * left this at 192/196 bytes with the callee-saved set rotated by one and
 * one "declined live-range split" (`mov r4, r1`).  That split is the MSL
 * spelling itself: the digit is stored with
 *
 *     result->sig.text[result->sig.length++] = val % 10;
 *
 * i.e. the post-increment of the length FIELD in the subscript, which keeps
 * the old length live across the _ull_mod call as its own value.  With that
 * one line the whole divmod loop is byte-exact.  The remaining residue (the
 * in-place reversal) closed on two points: `end` derived from `start`
 * (`start + length - 1`, not `text + length - 1`), and the swap written as
 * four separate statements with the pointer steps last
 * (`temp = *start; *start = *end; *end = temp; start++; end--;`) -- the
 * post-increment forms put start/end in each other's registers.  No zero
 * special case: a zero value leaves length 0 and exponent -1, as the image
 * does.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__ull2dec.c \
 *       --func __ull2dec --addr 0x020966B0 --cc 1.1p1 --arm
 *   EXACT, 196 bytes, 2 relocation sites, all resolved.
 */
void __ull2dec(decimal2 *result, u64 val)
{
    result->sign = 0;
    result->sig.length = 0;

    for (; val != 0; val /= 10)
        result->sig.text[result->sig.length++] = val % 10;

    {
        u8 *dec_start = result->sig.text;
        u8 *end = dec_start + result->sig.length - 1;

        while (dec_start < end) {
            u8 temp = *dec_start;
            *dec_start = *end;
            *end = temp;
            dec_start++;
            end--;
        }
    }

    result->exp = result->sig.length - 1;
}



/*
 * MSL __timesdec (ansi_fp.c): decimal * decimal -> decimal.  The Metrowerks
 * source verbatim: a 64-byte mantissa scratch filled backward from
 * `ip = mantissa + i + 1`, one column of `accumulator += *jp * *kp` per
 * output digit with the (j, k, l, t) window clamp, `% 10` / `/ 10` on an
 * unsigned long accumulator, exponents added as shorts, the leading carry
 * digit, a copy-out bounded at 32, and the round-half-even tail with its
 * `goto round` into __round_up (MSL_C_LIB_IncrementDigits).  Earlier lanes' hand bodies
 * sat at a one-register rotation of the callee-saved set; the original
 * declarations (in particular `ep = ip` as its own local and the per-column
 * block-scoped j/k/l/t) are what fix the allocation.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__timesdec.c \
 *       --func __timesdec --addr 0x02096774 --cc 1.1p1 --arm
 *   EXACT, 384 bytes, 1 relocation site, resolved.
 */
void __timesdec(decimal2 *result, const decimal2 *x, const decimal2 *y)
{
    unsigned long accumulator = 0;
    u8 mantissa[64];
    int i = x->sig.length + y->sig.length - 1;
    u8 *ip = mantissa + i + 1;
    u8 *ep = ip;

    result->sign = 0;

    for (; i > 0; i--) {
        int k = y->sig.length - 1;
        int j = i - k - 1;
        int l;
        int t;
        const u8 *jp;
        const u8 *kp;

        if (j < 0) {
            j = 0;
            k = i - 1;
        }

        jp = x->sig.text + j;
        kp = y->sig.text + k;
        l = k + 1;
        t = x->sig.length - j;

        if (l > t)
            l = t;

        for (; l > 0; l--, jp++, kp--)
            accumulator += *jp * *kp;

        *--ip = (u8)(accumulator % 10);
        accumulator /= 10;
    }

    result->exp = (s16)(x->exp + y->exp);

    if (accumulator > 0) {
        *--ip = (u8)accumulator;
        result->exp++;
    }

    for (i = 0; i < 32 && ip < ep; i++, ip++)
        result->sig.text[i] = *ip;

    result->sig.length = (u8)i;

    if (ip < ep && *ip >= 5) {
        if (*ip == 5) {
            u8 *jp = ip + 1;
            for (; jp < ep; jp++) {
                if (*jp != 0)
                    goto round;
            }
            if ((*(ip - 1) & 1) == 0)
                return;
        }
    round:
        MSL_C_LIB_IncrementDigits((u8 *)result, result->sig.length);
    }
}



/*
 * Decimal string to the packed digit record the bcd family shares: clear the
 * flag byte, store the caller's halfword parameter at +2, convert up to 32
 * digits into the byte array at +5, then decide whether the value is in range.
 * A string whose first unconsumed character is below '5' is accepted as is,
 * above '5' is rejected through MSL_C_LIB_IncrementDigits, and exactly '5' is accepted
 * only when some later digit is non-zero or the last converted digit is odd.
 *
 * The pointer is unsigned throughout: `const char *` gives `ldrsb` and signed
 * `poplt`/`ble` comparisons where the original has `ldrb` and the unsigned
 * `poplo`/`bhi`.
 *
 * Two spellings are pinned:
 *
 *  - all three rejection paths jump to one `tail` label, so the file has a
 *    single `bl 02096620`; writing the call out in each arm leaves three
 *    copies and 56 bytes of diff.
 *  - the trailing-zero scan is entered with `c = s[1]; s++;`, which is what
 *    the original's two-instruction entry (`ldrb r2, [r1, #1]` then `add r1,
 *    r1, #1`) is: the load is formed against the not-yet-incremented pointer
 *    and the increment follows.  The equivalent `s++; c = *s;` compiles to
 *    `add r1, r1, #1; ldrb r2, [r1]` - same length, same value, different
 *    order - and every later branch then targets an address four bytes off.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__str2dec.c \
 *       --func __str2dec --addr 0x020968F4 --cc 1.1p1 --arm
 *   EXACT, 156 bytes, 1 relocation site, resolved.
 */
void __str2dec(struct MslDecString *dec, const u8 *s, u16 exponent)
{
    int i;
    u8 c;

    dec->exp = exponent;
    dec->sign = 0;
    i = 0;
    while (i < 32 && *s != 0) {
        dec->digits[i] = (u8)(*s++ - '0');
        i++;
    }
    dec->length = (u8)i;
    if (*s == 0)
        return;
    if (*s < 5)
        return;
    if (*s > 5)
        goto tail;
    c = s[1];
    s++;
    while (c != 0) {
        if (c != '0')
            goto tail;
        c = *++s;
    }
last:
    if ((dec->digits[i - 1] & 1) == 0)
        return;
tail:
    MSL_C_LIB_IncrementDigits((u8 *)dec, dec->length);
}



/*
 * MSL __two_exp (ansi_fp.c): 2^exp as a decimal record.  A switch over the
 * tabulated exponents -64, -53, -32, -16 and -8..8, each arm handing a digit
 * string and a decimal exponent to __str2dec (__str2dec); every other
 * exponent recurses on exp/2 (spelled the MSL way,
 * `((long)((0x80000000UL & exp) >> 31) + exp) >> 1`), squares the half with
 * __timesdec (__timesdec), and on an odd exponent copies the result to a
 * stack temporary and multiplies by "2" (exp > 0) or "5"e-1.  `decimal x2,
 * temp;` in that order puts temp at sp+0 and x2 at sp+0x26.
 *
 * Earlier notes (docs/notes/pkt_02096990.c.txt) held this out of scope for
 * lack of witnesses on the 21 digit strings; under the widened sole-ref
 * class every one resolves (`string` or `sole-ref`), so the body is EXACT.
 * The strings are declared by address because they sit in the packed MSL
 * rodata area and mwcc would otherwise emit its own copies.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__two_exp.c \
 *       --func __two_exp --addr 0x02096990 --cc 1.1p1 --arm
 *   EXACT, 896 bytes, 46 relocation sites, all resolved.
 */
void __two_exp(decimal2 *result, long exp)
{
    switch (exp) {
    case -64:
        ((DecFromStr)__str2dec)(result, s_020A8ABC, -20);
        return;
    case -53:
        ((DecFromStr)__str2dec)(result, s_020A8AEC, -16);
        return;
    case -32:
        ((DecFromStr)__str2dec)(result, s_020A8B14, -10);
        return;
    case -16:
        ((DecFromStr)__str2dec)(result, s_020A8B2C, -5);
        return;
    case -8:
        ((DecFromStr)__str2dec)(result, s_020A8B3C, -3);
        return;
    case -7:
        ((DecFromStr)__str2dec)(result, s_020A8B44, -3);
        return;
    case -6:
        ((DecFromStr)__str2dec)(result, s_020A8B4C, -2);
        return;
    case -5:
        ((DecFromStr)__str2dec)(result, s_020A8B54, -2);
        return;
    case -4:
        ((DecFromStr)__str2dec)(result, s_020A8B5C, -2);
        return;
    case -3:
        ((DecFromStr)__str2dec)(result, s_020A8B60, -1);
        return;
    case -2:
        ((DecFromStr)__str2dec)(result, s_020A8B64, -1);
        return;
    case -1:
        ((DecFromStr)__str2dec)(result, s_020A8B68, -1);
        return;
    case 0:
        ((DecFromStr)__str2dec)(result, s_020A8B6C, 0);
        return;
    case 1:
        ((DecFromStr)__str2dec)(result, s_020A8B70, 0);
        return;
    case 2:
        ((DecFromStr)__str2dec)(result, s_020A8B74, 0);
        return;
    case 3:
        ((DecFromStr)__str2dec)(result, s_020A8B78, 0);
        return;
    case 4:
        ((DecFromStr)__str2dec)(result, s_020A8B7C, 1);
        return;
    case 5:
        ((DecFromStr)__str2dec)(result, s_020A8B80, 1);
        return;
    case 6:
        ((DecFromStr)__str2dec)(result, s_020A8B84, 1);
        return;
    case 7:
        ((DecFromStr)__str2dec)(result, s_020A8B88, 2);
        return;
    case 8:
        ((DecFromStr)__str2dec)(result, s_020A8B8C, 2);
        return;
    }

    {
        decimal2 x2, temp;

        __two_exp(&x2, ((long)((0x80000000UL & exp) >> 31) + exp) >> 1);
        __timesdec(result, &x2, &x2);
        if (exp & 1) {
            temp = *result;
            if (exp > 0)
                ((DecFromStr)__str2dec)(&x2, s_020A8B70, 0);
            else
                ((DecFromStr)__str2dec)(&x2, s_020A8B68, -1);
            __timesdec(result, &temp, &x2);
        }
    }
}



/*
 * String comparison over the length-prefixed string object used by the
 * 0x02096D10 family: byte +5 is a terminator flag, +2 is an s16 key, +4 is
 * the byte length and +5.. is the payload.  Two flag/length guards, a key
 * comparison, then a byte compare over the shorter of the two payloads; when
 * the compared prefix is exactly a's payload the tail of b is checked for a
 * terminator instead, and vice versa.  Returns 1 when the two are equivalent.
 *
 * Three measured levers (all needed, each costs a whole-function diff):
 *   - `volatile u8 f04`.  The second loop re-reads the length out of the
 *     object on every iteration (`ldrb r1, [r0, #4]` after the payload test)
 *     instead of hoisting it; a plain field lets mwcc hoist it and the loop
 *     comes out one instruction short.
 *   - the bound is an `int` copy: `la`/`lb` are locals, so `if (la > lb)`
 *     compares two sign-unknown ints and mwcc emits `movgt`.  Comparing the
 *     u8 fields directly tells mwcc both are 0..255 and it uses `movhi`
 *     instead, which is four bytes that differ.
 *   - `p = a; if (n == la) p = b;`.  As a ternary mwcc keeps the result in
 *     b's register (r1); the two-statement form lets it coalesce p with `a`
 *     and the whole tail allocates as the original does.
 */
int __equals_dec(MslStrRec *a, MslStrRec *b)
{
    MslStrRec *p;
    int i, n;
    int la, lb;

    if (a->data[0] == 0)
        return b->data[0] == 0;
    if (b->data[0] == 0)
        return a->data[0] == 0;
    if (a->key != b->key)
        goto fail;
    i = 0;
    la = a->length;
    lb = b->length;
    n = la;
    if (la > lb)
        n = lb;
    for (; i < n; i++) {
        if (a->data[i] != b->data[i])
            return 0;
    }
    p = a;
    if (n == la)
        p = b;
    for (; i < p->length; i++) {
        if (p->data[i] != 0)
            return 0;
    }
    return 1;
fail:
    return 0;
}



/*
 * The ordering sibling of __equals_dec: same length-prefixed string object
 * (byte +5 terminator flag, s16 key at +2, byte length at +4, payload from +5)
 * but it returns 1 when a sorts before b and 0 otherwise, so the payload loop
 * is a two-sided compare instead of a single inequality.  When the common
 * prefix is exactly a's payload, b's tail must hold terminators only, and a
 * non-terminator there means a is a proper prefix and sorts first (return 1);
 * the s16 keys break the tie when they differ.
 *
 * Levers, all measured:
 *   - `volatile u8 f04` again: the tail loop re-reads b's length every
 *     iteration (`ldrb r0, [r1, #4]` under the payload test) rather than
 *     hoisting it, so a plain field comes out four bytes short.
 *   - the tail is a do/while guarded by the second `&&`: `if (n == la && i <
 *     lb) { do {...} while (i < b->length); }`.  The entry test compares against
 *     the cached lb (r4) while the back edge re-reads b->length, which is what
 *     distinguishes this shape from `for (; i < lb; i++)` (whose back edge
 *     would use the cached value and lose the volatile read).
 *   - `if (a->key != b->key) goto keycmp; ... keycmp: return a->key < b->key;`
 *     -- the s16 tie-break sits out of line after the final `return 0`, as a
 *     single `if (...) return ...;` the front end if-converts it inline and
 *     the whole tail shifts.
 *   - `int lb, la;`: declaration order decides which of the two lengths gets
 *     r4 and which r5; the `la, lb` order swaps them and costs seven bytes.
 */
int __less_dec(MslStrRec *a, MslStrRec *b)
{
    int i, n;
    int lb, la;

    if (a->data[0] == 0)
        return b->data[0] != 0;
    if (b->data[0] == 0)
        return 0;
    if (a->key != b->key)
        goto keycmp;
    i = 0;
    la = a->length;
    lb = b->length;
    n = la;
    if (la > lb)
        n = lb;
    for (; i < n; i++) {
        if (a->data[i] < b->data[i])
            return 1;
        if (b->data[i] < a->data[i])
            return 0;
    }
    if (n == la && i < lb) {
        do {
            if (b->data[i] != 0)
                return 1;
            i++;
        } while (i < b->length);
    }
    return 0;
keycmp:
    return a->key < b->key;
}



/*
 * MSL __minus_dec (ansi_fp.c): z = x - y on decimal records, with rounding
 * of the digits of y that fall past z's precision.  Three lanes left a hand
 * body at 95 concrete bytes out with the size exact (an allocator tie between
 * the text base and the y->sig.length temporary, docs/notes/pkt_02096ED0.c.txt).
 * The Metrowerks source closes it outright: the declarations
 * `int zlen, dexp; u8 *ib, *i, *ie; const u8 *jb, *j, *jn;`, the borrow loops
 * written `while (*k == 0) --k; while (k != i) { --*k; *++k += 10; }`, the
 * round-down flag with `goto done` out of the trailing-zero scan, and the
 * `u8 dl` narrowing (the image's `and r5, r4, #0xff`) on the leading-zero
 * shift.  Argument order is (dest, minuend, subtrahend): the 38-byte opening
 * copy is `*z = *x`.  No relocations.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__minus_dec.c \
 *       --func __minus_dec --addr 0x02096ED0 --cc 1.1p1 --arm
 *   EXACT, 672 bytes, 0 relocation sites.
 */
void __minus_dec(decimal2 *z, const decimal2 *x, const decimal2 *y)
{
    int zlen, dexp;
    u8 *ib, *i, *ie;
    const u8 *jb, *j, *jn;

    *z = *x;

    if (y->sig.text[0] == 0)
        return;

    zlen = z->sig.length;
    if (zlen < y->sig.length)
        zlen = y->sig.length;

    dexp = z->exp - y->exp;
    zlen += dexp;

    if (zlen > 32)
        zlen = 32;

    while (z->sig.length < zlen)
        z->sig.text[z->sig.length++] = 0;

    ib = z->sig.text;
    i = ib + zlen;

    if (y->sig.length + dexp < zlen)
        i = ib + (y->sig.length + dexp);

    jb = y->sig.text;
    j = jb + (i - ib - dexp);
    jn = j;

    while (i > ib && j > jb) {
        --i;
        --j;
        if (*i < *j) {
            u8 *k = i - 1;
            while (*k == 0)
                --k;
            while (k != i) {
                --*k;
                *++k += 10;
            }
        }
        *i -= *j;
    }

    if (jn - jb < y->sig.length) {
        int round_down = 0;
        if (*jn < 5)
            round_down = 1;
        else if (*jn == 5) {
            const u8 *je = y->sig.text + y->sig.length;

            for (j = jn + 1; j < je; ++j)
                if (*j != 0)
                    goto done;

            i = ib + (jn - jb) + dexp - 1;

            if (*i & 1)
                round_down = 1;
        }
        if (round_down) {
            if (*i < 1) {
                u8 *k = i - 1;

                while (*k == 0)
                    --k;
                while (k != i) {
                    --*k;
                    *++k += 10;
                }
            }

            *i -= 1;
        }
    }
done:
    for (i = ib; *i == 0; ++i) {
    }

    if (i > ib) {
        u8 dl = (u8)(i - ib);
        z->exp -= dl;
        ie = ib + z->sig.length;
        for (; i < ie; ++i, ++ib)
            *ib = *i;
        z->sig.length -= dl;
    }

    ib = z->sig.text;

    for (i = ib + z->sig.length; i > ib;) {
        --i;
        if (*i != 0)
            break;
    }

    z->sig.length = (u8)(i - ib + 1);
}



/*
 * MSL `__num2dec` -- convert a double to the 38-byte packed decimal record
 * (DB) that this family's other functions add, subtract, multiply and print.
 * The record is { u8 sign; u8 pad; s16 exp10; u8 ndigits; u8 digits[33] }.
 *
 * Three paths:
 *   1. x == 0.0                 -> sign, exp 0, one digit, digit = 0.
 *   2. NaN or infinity          -> __fpclassifyd (the MSL fpclassify: 1 = NaN,
 *      2 = Inf, 3 = zero, 4 = normal, 5 = subnormal) returns <= 2; the record
 *      gets one digit, 'N' (0x4E) for NaN and 'I' (0x49) for infinity.  The
 *      classify call is written TWICE, once for the guard and once for the
 *      digit, because the image calls 0x020921F4 twice (0x02097170+0x70 and
 *      +0x94); a cached result loses the second `bl`.
 *   3. finite non-zero: take the absolute value (`0.0 - x` through _dsub),
 *      frexp it into f in [0.5,1) with binary exponent e, then work out how
 *      many mantissa bits are significant:
 *        v  = the mantissa bits of f with the hidden bit forced on
 *        k  = 53 - popcount64((v & -v) - 1)      -- 53 minus the trailing
 *             zero count, i.e. the number of significant mantissa bits
 *      `__two_exp(&b, e - k)` builds the decimal record of 2^(e-k) (the
 *      recursive power-of-two formatter, dense switch over -32..+8), and
 *      `__ull2dec(&a, (u64)ldexp(f, k))` builds the decimal record of the
 *      exact integer mantissa.  `__timesdec(r, &a, &b)` multiplies the two
 *      records, and the sign is stamped last.
 *
 * THE ONE LEVER, and it is worth four instructions (376 bytes against 384).
 * `g = f;` before the bit read.  The bit pattern is taken through the address
 * of a SECOND double (`*(u64 *)&g`), not of `f` itself.  With one variable,
 * mwcc gives `f` a stack home, writes it there and RELOADS it with
 * `ldr r0,[sp] / ldr r1,[sp,#4]` after the popcount call for the ldexp
 * argument.  With the copy, `f` stays a pure register value in r4:r6 across
 * both calls (`mov r4,r0 / mov r6,r1` after frexp, `mov r0,r4 / mov r1,r6`
 * before ldexp) and only `g`'s home is written (`str r4,[sp] / str r6,[sp,#4]`
 * at +0x118), which is exactly the image.  That copy is also what widens the
 * prologue to `push {r3-r8,sb,lr}`: one more callee-saved register is needed
 * to hold f across the popcount.  A union over one variable does NOT do it --
 * it compiles byte for byte the same as the single-variable form.
 *
 * The zero test is spelled `x == 0.0`, a real double comparison, not a call:
 * mwcc lowers it to `bl _deq` (0x0209BA3C, __dcmp_5) followed IMMEDIATELY by
 * the conditional branch, because the helper returns condition flags.  An
 * explicit `extern int func_0209BA3C(double, double)` whose result is tested
 * costs an extra `cmp r0, #0`.  `_deq` is the name mwcc emits, so it is what
 * the symbols: block has to pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__num2dec.c \
 *       --func __num2dec --addr 0x02097170 --cc 1.1p1 --arm
 *   EXACT, 384 bytes, 12 of 12 relocation sites resolved.
 */
void __num2dec(DB *r, double x)
{
    DB a;
    DB b;
    int e;
    u64 v;
    int k;
    double f;
    double g;
    u8 neg;

    neg = __signbitd(x) != 0;
    if (x == 0.0) {
        r->sign = neg;
        r->exp = 0;
        r->length = 1;
        r->digits[0] = 0;
        return;
    }
    if (__fpclassifyd(x) <= 2) {
        r->sign = neg;
        r->exp = 0;
        r->length = 1;
        r->digits[0] = (__fpclassifyd(x) == 1) ? 0x4E : 0x49;
        return;
    }
    if (neg)
        x = func_0209AF34(0.0, x);
    f = frexp(x, &e);
    g = f;
    v = *(u64 *)&g | 0x0010000000000000ULL;
    k = 0x35 - MSL_C_LIB_PopCount64((v & -v) - 1);
    __two_exp((struct decimal2 *)(&b), e - k);
    __ull2dec((struct decimal2 *)(&a), func_0209C554(ldexp(f, k)));
    __timesdec((struct decimal2 *)r, (const struct decimal2 *)(&a), (const struct decimal2 *)(&b));
    r->sign = neg;
}



void __dtoa(const decform *f, double x, decimal *p)
{
    int n = f->digits;
    int i;

    __num2dec((DB *)p, x);
    if (p->sig.text[0] > 9)
        return;
    if (n > 0x20)
        n = 0x20;
    MSL_C_LIB_SetPrecision((DB *)p, n);
    while (p->sig.length < n)
        p->sig.text[p->sig.length++] = 0;
    p->exp -= (s16)(p->sig.length - 1);
    for (i = 0; i < p->sig.length; i++)
        p->sig.text[i] += 0x30;
}



/*
 * MSL ansi_fp.c __dec2num (decimal record -> double), written fresh in the
 * MSL layout (wave 18).  Callees: copysign 0x0209A368, __str2dec 0x020968F4,
 * __less_dec 0x02096DF0, __equals_dec 0x02096D10, __minus_dec 0x02096ED0,
 * __num2dec_internal 0x02097170, pow 0x0209AB80, ldexp 0x0209A7A8,
 * __fpclassifyd 0x020921F4.  EXACT under dsi/1.1p1 and dsi/1.2 alike.
 *
 * The refinement loop tests is_low directly (`if (is_low) { ++; isinf exit }
 * else --`); there is no is_high variable.  The image's `mov r7, #1 /
 * movne r7, #0` before the loop is the compiler's negated if-condition
 * (!is_low), hoisted as a loop invariant.  An explicit is_high = !is_low with
 * `if (!is_high)` gives the same loop body but makes 1.1p1 hoist &x64, &dec
 * and the `& 1` mask's zero to +0x2A0 instead of the loop preheader +0x3A4
 * (the 718-721 byte wall of waves 9 to 17).  is_low is initialised to 0 at
 * its declaration and set by `if (__less_dec(...)) is_low = 1`; ll points at
 * guess from its declaration.
 */
double __dec2num(const decimal2 *d)
{
    if (d->sig.length <= 0)
        return copysign(0.0, d->sign == 0 ? 1.0 : -1.0);

    switch (d->sig.text[0]) {
    case '0':
        return copysign(0.0, d->sign == 0 ? 1.0 : -1.0);
    case 'I':
        return copysign((double)__float_huge, d->sign == 0 ? 1.0 : -1.0);
    case 'N':
        {
            double result;
            unsigned long long *ll = (unsigned long long *)&result;

            *ll = 0x7FF0000000000000ULL;
            if (d->sign)
                *ll |= 0x8000000000000000ULL;
            *ll |= 0x0008000000000000ULL;
            return result;
        }
    }

    {
        decimal2 dec = *d;
        unsigned char *i = dec.sig.text;
        unsigned char *e = i + dec.sig.length;
        double first_guess;
        int exponent;

        for (; i < e; ++i)
            *i -= '0';
        dec.exp += dec.sig.length - 1;
        exponent = dec.exp;

        {
            decimal2 max;

            __str2dec((struct MslDecString *)(&max), (const u8 *)s_020A8B90, 308);
            if (__less_dec((MslStrRec *)&max, (MslStrRec *)&dec))
                return copysign((double)__float_huge, d->sign == 0 ? 1.0 : -1.0);
        }

        i = dec.sig.text;
        first_guess = *i++;

        while (i < e) {
            unsigned long ival = 0;
            int j;
            double temp1, temp2;
            int ndig = (int)(e - i) % 8;

            if (ndig == 0)
                ndig = 8;
            for (j = 0; j < ndig; ++j, ++i)
                ival = ival * 10 + *i;
            temp1 = first_guess * pow_10[ndig - 1];
            temp2 = temp1 + ival;
            if (ival != 0 && temp1 == temp2)
                break;
            first_guess = temp2;
            exponent -= ndig;
        }

        if (exponent < 0)
            first_guess /= pow(5.0, -exponent);
        else
            first_guess *= pow(5.0, exponent);

        first_guess = ldexp(first_guess, exponent);
        if (isinf(first_guess))
            *(unsigned long long *)&first_guess = 0x7FEFFFFFFFFFFFFFULL;

        {
            decimal2 feval, feval2;
            decimal2 difflow, diffhigh;
            double guess;
            unsigned long long *ll = (unsigned long long *)&guess;
            int is_low = 0;

            __num2dec((DB *)&feval, first_guess);
            if (__equals_dec((MslStrRec *)&feval, (MslStrRec *)&dec))
                goto done;
            if (__less_dec((MslStrRec *)&feval, (MslStrRec *)&dec))
                is_low = 1;
            guess = first_guess;
            for (;;) {
                if (is_low) {
                    ++*ll;
                    if (isinf(guess))
                        goto done;
                } else
                    --*ll;
                __num2dec((DB *)&feval2, guess);
                if (is_low && !__less_dec((MslStrRec *)&feval2, (MslStrRec *)&dec))
                    break;
                if (!is_low && !__less_dec((MslStrRec *)&dec, (MslStrRec *)&feval2)) {
                    double tg;

                    difflow = feval;
                    feval = feval2;
                    feval2 = difflow;
                    tg = first_guess;
                    first_guess = guess;
                    guess = tg;
                    break;
                }
                feval = feval2;
                first_guess = guess;
            }
            __minus_dec(&difflow, &dec, &feval);
            __minus_dec(&diffhigh, &feval2, &dec);
            if (__equals_dec((MslStrRec *)&difflow, (MslStrRec *)&diffhigh)) {
                if (*(unsigned long long *)&first_guess & 1)
                    first_guess = guess;
            } else if (!__less_dec((MslStrRec *)&difflow, (MslStrRec *)&diffhigh))
                first_guess = guess;
        }
done:
        if (dec.sign)
            first_guess = -first_guess;
        return first_guess;
    }
}



double scalbn(double x, int n)
{
    int t;
    double v = frexp(x, &t);
    t += n;
    return ldexp(v, t);
}



static const double
zero    =  0.0,
one	=  1.0,
two	=  2.0,
two53	=  9007199254740992.0,
huge	=  1.0e300,
tiny    =  1.0e-300,
L1  =  5.99999999999994648725e-01,
L2  =  4.28571428578550184252e-01,
L3  =  3.33333329818377432918e-01,
L4  =  2.72728123808534006489e-01,
L5  =  2.30660745775561754067e-01,
L6  =  2.06975017800338417784e-01,
P1   =  1.66666666666666019037e-01,
P2   = -2.77777777770155933842e-03,
P3   =  6.61375632143793436117e-05,
P4   = -1.65339022054652515390e-06,
P5   =  4.13813679705723846039e-08,
lg2  =  6.93147180559945286227e-01,
lg2_h  =  6.93147182464599609375e-01,
lg2_l  = -1.90465429995776804525e-09,
ovt =  8.0085662595372944372e-0017,
cp    =  9.61796693925975554329e-01,
cp_h  =  9.61796700954437255859e-01,
cp_l  = -7.02846165095275826516e-09,
ivln2    =  1.44269504088896338700e+00,
ivln2_h  =  1.44269502162933349609e+00,
ivln2_l  =  1.92596299112661746887e-08;



/*
 * MSL __ieee754_pow(x, y): fdlibm e_pow.c with the MSL edits listed in
 * docs/notes/pkt_020979C0.c.txt.  fabs = fabs, sqrt = func_0209C5E0.
 * The machine entry is 0x020979BC (push {r0-r3} home for the register-passed
 * doubles), four bytes before the disasm body label __ieee754_pow.
 *
 * Front end dsi/1.2 (1.2p2 identical): kept &bp base across its three uses
 * and the push {r3-fp,lr} / sub sp,#0x78 frame; 1.1p1 splits the loads and
 * builds a different frame.
 *
 * The self-assignment `s = s;` after `p_h = y1*t1` emits no code; it is what
 * settles the r6/r7/r8 coloring of t2 (hi), s and the final exponent n over
 * 0x0BC8..0x1170 (without it the three rotate, 25 bytes out).  Found by the
 * permuter (wave 18, seed 1902) and reduced by hand to this one line.
 */
double __ieee754_pow(double x, double y)
{
	double z,ax,z_h,z_l,p_h,p_l;
	double y1,t1,t2,r,s,t,u,v,w;
	i32 i,j,k,yisint,n,n0;
	i32 hx,hy,ix,iy;
	u32 lx,ly;

	hx = HI(x); lx = LO(x);
	hy = HI(y); ly = LO(y);
	ix = hx&0x7fffffff;  iy = hy&0x7fffffff;

	if((iy|ly)==0) return one;

	if(ix > 0x7ff00000 || ((ix==0x7ff00000)&&(lx!=0)) ||
	   iy > 0x7ff00000 || ((iy==0x7ff00000)&&(ly!=0)))
		return x+y;

	yisint  = 0;
	if(hx<0) {
	    if(iy>=0x43400000) yisint = 2;
	    else if(iy>=0x3ff00000) {
		k = (iy>>20)-0x3ff;
		if(k>20) {
		    j = ly>>(52-k);
		    if((j<<(52-k))==ly) yisint = 2-(j&1);
		} else if(ly==0) {
		    j = iy>>(20-k);
		    if((j<<(20-k))==iy) yisint = 2-(j&1);
		}
	    }
	}

	if(ly==0) {
	    if (iy==0x7ff00000) {
	        if(((ix-0x3ff00000)|lx)==0)
		    return  y - y;
	        else if (ix >= 0x3ff00000)
		    return (hy>=0)? y: zero;
	        else
		    return (hy<0)?-y: zero;
	    }
	    if(iy==0x3ff00000) {
		if(hy<0) return one/x; else return x;
	    }
	    if(hy==0x40000000) return x*x;
	    if(hy==0x3fe00000) {
		if(hx>=0)
		return func_0209C5E0(x);
	    }
	}

	ax   = fabs(x);
	if(lx==0) {
	    if(ix==0x7ff00000||ix==0||ix==0x3ff00000){
		z = ax;
		if(hy<0) z = one/z;
		if(hx<0) {
		    if(((ix-0x3ff00000)|yisint)==0) {
			z = (z-z)/(z-z);
		    } else if(yisint==1)
			z = -z;
		}
		return z;
	    }
	}

	n0 = (hx>>31)+1;

	if((n0|yisint)==0) {
	    errno = 33;
	    return __float_nan;
	}

	if(iy>0x41e00000) {
	    if(iy>0x43f00000){
		if(ix<=0x3fefffff) return (hy<0)? huge*huge:tiny*tiny;
		if(ix>=0x3ff00000) return (hy>0)? huge*huge:tiny*tiny;
	    }
	    if(ix<0x3fefffff) return (hy<0)? huge*huge:tiny*tiny;
	    if(ix>0x3ff00000) return (hy>0)? huge*huge:tiny*tiny;
	    t = x-one;
	    w = (t*t)*(0.5-t*(0.3333333333333333333333-t*0.25));
	    u = ivln2_h*t;
	    v = t*ivln2_l-w*ivln2;
	    t1 = u+v;
	    LO(t1) = 0;
	    t2 = v-(t1-u);
	} else {
	    double ss,s2,s_h,s_l,t_h,t_l;
	    n = 0;
	    if(ix<0x00100000)
		{ax *= two53; n -= 53; ix = HI(ax); }
	    n  += ((ix)>>20)-0x3ff;
	    j  = ix&0x000fffff;
	    ix = j|0x3ff00000;
	    if(j<=0x3988E) k=0;
	    else if(j<0xBB67A) k=1;
	    else {k=0;n+=1;ix -= 0x00100000;}
	    HI(ax) = ix;

	    u = ax-bp[k];
	    v = one/(ax+bp[k]);
	    ss = u*v;
	    s_h = ss;
	    LO(s_h) = 0;
	    t_h = zero;
	    HI(t_h)=((ix>>1)|0x20000000)+0x00080000+(k<<18);
	    t_l = ax - (t_h-bp[k]);
	    s_l = v*((u-s_h*t_h)-s_h*t_l);
	    s2 = ss*ss;
	    r = s2*s2*(L1+s2*(L2+s2*(L3+s2*(L4+s2*(L5+s2*L6)))));
	    r += s_l*(s_h+ss);
	    s2  = s_h*s_h;
	    t_h = 3.0+s2+r;
	    LO(t_h) = 0;
	    t_l = r-((t_h-3.0)-s2);
	    u = s_h*t_h;
	    v = s_l*t_h+t_l*ss;
	    p_h = u+v;
	    LO(p_h) = 0;
	    p_l = v-(p_h-u);
	    z_h = cp_h*p_h;
	    z_l = cp_l*p_h+p_l*cp+dp_l[k];
	    t = (double)n;
	    t1 = (((z_h+z_l)+dp_h[k])+t);
	    LO(t1) = 0;
	    t2 = z_l-(((t1-t)-dp_h[k])-z_h);
	}

	s = one;
	if((n0|(yisint-1))==0) s = -one;

	y1  = y;
	LO(y1) = 0;
	p_l = (y-y1)*t1+y*t2;
	p_h = y1*t1;
	s = s;		/* no code; pins the t2/s/n register coloring */
	z = p_l+p_h;
	j = HI(z);
	i = LO(z);
	if (j>=0x40900000) {
	    if(((j-0x40900000)|i)!=0)
		return s*huge*huge;
	    else {
		if(p_l+ovt>z-p_h) return s*huge*huge;
	    }
	} else if((j&0x7fffffff)>=0x4090cc00 ) {
	    if(((j-0xc090cc00)|i)!=0)
		return s*tiny*tiny;
	    else {
		if(p_l<=z-p_h) return s*tiny*tiny;
	    }
	}
	i = j&0x7fffffff;
	k = (i>>20)-0x3ff;
	n = 0;
	if(i>0x3fe00000) {
	    n = j+(0x00100000>>(k+1));
	    k = ((n&0x7fffffff)>>20)-0x3ff;
	    t = zero;
	    HI(t) = (n&~(0x000fffff>>k));
	    n = ((n&0x000fffff)|0x00100000)>>(20-k);
	    if(j<0) n = -n;
	    p_h -= t;
	}
	t = p_l+p_h;
	LO(t) = 0;
	u = t*lg2_h;
	v = (p_l-(t-p_h))*lg2+t*lg2_l;
	z = u+v;
	w = v-(z-u);
	t  = z*z;
	t1  = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
	r  = (z*t1)/(t1-two)-(w+z*w);
	z  = one-(r-z);
	j  = HI(z);
	j += (n<<20);
	if((j>>20)<=0) z = scalbn(z,n);
	else HI(z) += (n<<20);
	return s*z;
}



static const double
half =  5.00000000000000000000e-01,
two24 =  1.67772160000000000000e+07,
invpio2 =  6.36619772367581382433e-01,
pio2_1  =  1.57079632673412561417e+00,
pio2_1t =  6.07710050650619224932e-11,
pio2_2  =  6.07710050630396597660e-11,
pio2_2t =  2.02226624879595063154e-21,
pio2_3  =  2.02226624871116645580e-21,
pio2_3t =  8.47842766036889956997e-32;



/*
 * fdlibm __ieee754_rem_pio2(x, y), e_rem_pio2.c transcribed unchanged.  The
 * machine entry is 0x02098B44, four bytes before the disasm body label
 * __ieee754_rem_pio2: the compiler's push {r0-r3} spilling the register-passed
 * double, because HI(x) takes the address of x.  The body is MSL runtime
 * (layout/runtime_arm9.txt, _msl_double_fn_1); the unit exists so the 4-byte
 * worklist row at the stub is reproduced as part of its function.
 *
 * Front end dsi/1.2 (wave 17): the loop store tx[i] = (double)(int)z is two
 * str (1.1p1 merges them into stm), the same pin that fits __ieee754_pow at
 * 0x020979BC.  Fabs = fabs, __kernel_rem_pio2 = __kernel_rem_pio2;
 * npio2_hw and two_over_pi resolve through the sole-ref/data class.
 */
int __ieee754_rem_pio2(double x, double *y)
{
    double z, w, t, r, fn;
    double tx[3];
    int e0, i, j, nx, n, ix, hx;

    hx = HI(x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3fe921fb)
    {
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    if (ix < 0x4002d97c)
    {
        if (hx > 0)
        {
            z = x - pio2_1;
            if (ix != 0x3ff921fb)
            {
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            }
            else
            {
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        }
        else
        {
            z = x + pio2_1;
            if (ix != 0x3ff921fb)
            {
                y[0] = z + pio2_1t;
                y[1] = (z - y[0]) + pio2_1t;
            }
            else
            {
                z += pio2_2;
                y[0] = z + pio2_2t;
                y[1] = (z - y[0]) + pio2_2t;
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb)
    {
        t = fabs(x);
        n = (int)(t * invpio2 + half);
        fn = (double)n;
        r = t - fn * pio2_1;
        w = fn * pio2_1t;
        if (n < 32 && ix != npio2_hw[n - 1])
        {
            y[0] = r - w;
        }
        else
        {
            j = ix >> 20;
            y[0] = r - w;
            i = j - (((HI(y[0])) >> 20) & 0x7ff);
            if (i > 16)
            {
                t = r;
                w = fn * pio2_2;
                r = t - w;
                w = fn * pio2_2t - ((t - r) - w);
                y[0] = r - w;
                i = j - (((HI(y[0])) >> 20) & 0x7ff);
                if (i > 49)
                {
                    t = r;
                    w = fn * pio2_3;
                    r = t - w;
                    w = fn * pio2_3t - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0)
        {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        }
        else
            return n;
    }
    if (ix >= 0x7ff00000)
    {
        y[0] = y[1] = x - x;
        return 0;
    }
    LO(z) = LO(x);
    e0 = (ix >> 20) - 1046;
    HI(z) = ix - (e0 << 20);
    for (i = 0; i < 2; i++)
    {
        tx[i] = (double)((int)(z));
        z = (z - tx[i]) * two24;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == zero)
        nx--;
    n = __kernel_rem_pio2(tx, y, e0, nx, 2, two_over_pi);
    if (hx < 0)
    {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}



double __kernel_cos(double x, double y)
{
    static const double one = 1.00000000000000000000e+00;
    static const double C1 = 4.16666666666666019037e-02;
    static const double C2 = -1.38888888888741095749e-03;
    static const double C3 = 2.48015872894767294178e-05;
    static const double C4 = -2.75573143513906633035e-07;
    static const double C5 = 2.08757232129817482790e-09;
    static const double C6 = -1.13596475577881948265e-11;

    double a, hz, z, r, qx;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix < 0x3e400000)
    {
        if ((int)x == 0)
            return one;
    }
    z = x * x;
    r = z * (C1 + z * (C2 + z * (C3 + z * (C4 + z * (C5 + z * C6)))));
    if (ix < 0x3FD33333)
        return one - (0.5 * z - (z * r - x * y));
    else
    {
        if (ix > 0x3fe90000)
        {
            qx = 0.28125;
        }
        else
        {
            HI(qx) = ix - 0x00200000;
            LO(qx) = 0;
        }
        hz = 0.5 * z - qx;
        a = one - qx;
        return a - (hz - (z * r - x * y));
    }
}
