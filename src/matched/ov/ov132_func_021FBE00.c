/*
 * function: func_021FBE00
 * address: 0x021FBE00
 * packet: pkt_ov132_021FBE00
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of zero alignment padding follow the 54-byte body.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F9DB0 0x021F9DB0 thumb ov132
 *   func_021F9DB8 0x021F9DB8 thumb ov132
 *   func_021F6B80 0x021F6B80 thumb ov112
 *   func_021F6BC0 0x021F6BC0 thumb ov112
 */
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern void *func_021F9DAC(void *);
extern unsigned int *func_021F9DB0(void *,unsigned char);
extern void func_021F9DB8(void *,unsigned int *,unsigned char);
extern void func_021F6B80(unsigned int *,unsigned int *);
extern void func_021F6BC0(char *,unsigned int *,unsigned int);
int func_021FBE00(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char **)p;n=func_0201134C(*(struct Cursor **)(p+4));ctx=func_021F9DAC(*(void **)(obj+0x34));func_021F6B80(ctx,func_021F9DB0(*(void **)(obj+0x34),n));func_021F9DB8(*(void **)(obj+0x34),0,n);return 0; }
