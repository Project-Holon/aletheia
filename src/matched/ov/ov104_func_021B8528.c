/*
 * function: func_021B8528
 * address: 0x021B8528
 * packet: pkt_ov104_021B8528
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 174 code bytes then two zero alignment bytes before 021B85D8.
 * symbols:
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B818C 0x021B818C thumb ov104
 *   func_021B630C 0x021B630C thumb ov101
 *   func_021B7F1C 0x021B7F1C thumb ov104
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021B6480(int *p);
extern int func_021B630C(int *p, int value);
extern void func_021B818C(u8 *);
extern void func_021B7F1C(u8 *,void *,int,int,s16);
#define CTX(p) (*(u8 **)((p)+0x8b0))
void func_021B8528(u8 *p,u16 *state) { switch(*state) { case 0: if(func_021B6480(*(void **)(CTX(p)+4))>0) { CTX(p)[0x10]=0; *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); return; } if(func_021B6480(*(void **)(CTX(p)+4))<0) *state=1; break; case 1: CTX(p)[0x10]=0; *(u32 *)(CTX(p)+0xc)=2; *state=2; break; case 2: func_021B7F1C(p+0xcc,p+0xbc,4,0,0); *state=3; break; case 3: if(func_021B630C(*(void **)(CTX(p)+4),6)) *state=4; break; case 4: func_021B818C(p); break; } }
