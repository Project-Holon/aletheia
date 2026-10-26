#ifndef GAME_ARM9_MSL_STDIO_H
#define GAME_ARM9_MSL_STDIO_H

typedef struct FILE FILE;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_stdio.c, prototypes copied from their definitions. */

struct MslStream;
struct FILE;
typedef struct FILE FILE;

#include "../types.h"
#include "../arm9/msl_crt_shared_types.h"

void __prep_buffer(struct MslStream *stream);
int __load_buffer(struct MslStream *stream, size_t *bytes_loaded, int mode);
int __flush_buffer(struct MslStream *stream, u32 *bytes_flushed);
int fread(void *ptr, u32 memb_size, u32 num_memb, FILE *stream);
size_t __fread(void *ptr, size_t memb_size, size_t num_memb, FILE *file);
int fclose(FILE *stream);
int MSL_C_LIB_FlushStream(struct MslStream *stream);
int MSL_C_LIB_StrNICmp(const u8 *s1, const u8 *s2, int n);
int __ftell(struct MslStream *stream);
int ftell(FILE *stream);
int __fseek(MslStream *stream, u32 pos, u32 whence);
int fseek(FILE *stream, u32 pos, u32 whence);
int rewind(void *stream);
u32 MSL_C_LIB_PopCount64(u64 x);
int __signbitd(double x);
int __fpclassifyd(double x);
int MSL_C_LIB_MbrToWc(unsigned short *pwc, const unsigned char *s, unsigned int n);
int MSL_C_LIB_WcToMb(char *s, unsigned short wc);
u32 MSL_C_LIB_CallFormatHook(u32 *dst, u32 c);
u32 MSL_C_LIB_WideToNarrow(u8 *dst, const u16 *src, u32 max);
/* END mkheaders: generated region */

#endif
