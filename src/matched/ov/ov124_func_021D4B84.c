/*
 * function: func_021D4B84
 * address: 0x021D4B84
 * packet: pkt_ov124_021D4B84
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4280 0x021D4280 thumb ov124
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S020315D4;
extern void func_021D4280(char *);
extern void func_020307B0(void *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(void *);
int func_021D4B84(struct S020315D4 *task,int b,int keep,char *p) {func_021D4280(p);if(keep==0){func_020307B0(**(void ***)(p+4));func_020307B0(*(void **)(p+4));}func_020315D4(task);func_020306F0((void *)0x8a);return 1;}
