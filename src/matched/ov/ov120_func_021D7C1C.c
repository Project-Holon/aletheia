/*
 * function: func_021D7C1C
 * address: 0x021D7C1C
 * packet: pkt_ov120_021D7C1C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_0201DD78 0x0201DD78 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_020452E8(void *);
extern void func_0201DD78(int,int,int);
void func_021D7C1C(char *p) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)p+(u32)i*4); if(*(void **)(q+0x38)) { func_020452E8(*(void **)(q+0x38)); *(void **)(q+0x38)=0; } } func_0201DD78(1,2,0); }
