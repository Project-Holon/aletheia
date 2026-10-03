/*
 * function: func_021F9774, func_021F979C
 * unit: yes
 * extent: empty-return follower 0x021F979C; trailing two-byte padding.
 * address: 0x021F9774
 * packet: pkt_ov186_021F9774
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern int func_021FC4DC(int);
void func_021F9774(char *p,char *q) { *(int *)(p+8)=*(int *)(q+4);*(int *)p=*(int *)(q+12);*(int *)(p+12)=*(int *)(q+8);*(int *)(p+4)=func_021FC4DC(*(int *)q);*(int *)(p+16)=*(int *)(q+20);*(int *)(p+20)=*(int *)(*(char **)(*(char **)(q+24)+12)+4); }
void func_021F979C(void) {}
