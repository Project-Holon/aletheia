/*
 * function: func_02205D28
 * address: 0x02205D28
 * packet: pkt_ov195_02205D28
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   func_022065C8 0x022065C8 thumb ov195
 *   func_0220623C 0x0220623C thumb ov195
 *   func_022060BC 0x022060BC thumb ov195
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Owner Owner;
extern void func_022065C8(char *);
extern void func_0220623C(Owner *);
extern void func_022060BC(char *);
extern void func_020307B0(void *);
void func_02205D28(char *p){func_022065C8(p);func_0220623C((Owner *)p);func_022060BC(p);if(*(void **)(p+16))func_020307B0(*(void **)(p+16));func_020307B0(p);}
