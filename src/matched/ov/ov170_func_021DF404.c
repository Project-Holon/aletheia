/*
 * function: func_021DF404
 * address: 0x021DF404
 * packet: pkt_ov170_021DF404
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02007898 0x02007898 thumb
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void func_02007898(void *save, u32 box, const void *src);
extern int func_0216C0C0(int);
extern void func_02045808(struct U16Vec *);
extern void func_020307B0(void *);
int func_021DF404(u8 *p){char **q;q=*(char ***)(p+12);if(*(u32 *)(*q+0x1c)==0)func_02007898(*(void **)(*(char **)p+4),p[0x14],*(void **)(*q+0x20));*(u16 *)(p+0x10)=*(u32 *)(*q+0x1c);func_0216C0C0((int)*q);func_02045808((struct U16Vec *)q[1]);func_020307B0(*(void **)(p+12));return 0;}
