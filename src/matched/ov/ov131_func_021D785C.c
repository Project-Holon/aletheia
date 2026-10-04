/*
 * function: func_021D785C
 * address: 0x021D785C
 * packet: pkt_ov131_021D785C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-02 relaunch R9. The +0xAA/+0xAC str/movs swap was a
 *   scheduler effect of the pre-allocation instruction count before group 2
 *   (a no-arg call inserted earlier shifts it; a band of 5 positions swaps).
 *   func_020173B4 is declared void(void *): its body only forwards to
 *   func_02015F2C, and an int return adds one result copy per call, which
 *   put the second store inside the band. ov195 declares it the same way.
 * symbols:
 *   d_021DC1F8 0x021DC1F8 data ov131 a4
 *   d_021DC240 0x021DC240 data ov131 a4
 *   d_021DC180 0x021DC180 data a4
 *   d_021DC1C8 0x021DC1C8 data ov131 a4
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_021D7A44 0x021D7A44 thumb ov131
 *   func_021D79A8 0x021D79A8 thumb ov131
 *   func_021D7A1C 0x021D7A1C thumb ov131
 *   func_02015D80 0x02015D80 thumb
 *   func_02015D30 0x02015D30 thumb
 *   func_02015CDC 0x02015CDC thumb
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 */
#include "../include/Obj00112.h"
#include "../include/Obj00994.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { u32 x,y,z; } Vec;
extern const Vec d_021DC1F8,d_021DC240,d_021DC180,d_021DC1C8;
extern int func_021D60A4(char *p);
extern void func_021D7A44(void *,int,int *,int *);
extern void func_021D79A8(void *p, unsigned char *q, int radius);
extern void func_021D7A1C(void *,void *,Vec *);
extern void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void func_02015FD4(char *,int);
extern void func_02015D80(u8 *,u16);
extern void func_02015D30(void *,u32 *);
extern void func_020173B4(void *);
extern void func_02015CDC(void *,u32 *);
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
void func_021D785C(u8 *p,u8 *q,void *mon)
{
    Vec a=d_021DC1F8;
    Vec b=d_021DC240;
    Vec c=d_021DC180;
    Vec d=d_021DC1C8;
    void *m=(void *)func_021D60A4((void *)p);
    func_021D7A44((void *)p,(int)q,(int *)&a,(int *)&b);
    ((struct Obj00994 *)q)->f0=func_02017270(((struct Obj00112 *)p)->f78,m,0,0xd8000,0x48000,0);
    func_02015FD4(*(char * *)&((struct Obj00994 *)q)->f0,2);
    func_02015D80(*(u8 * *)&((struct Obj00994 *)q)->f0,0xd555);
    func_02015D30(((struct Obj00994 *)q)->f0,&b.x);
    func_020173B4(((struct Obj00994 *)q)->f0);
    func_02015CDC(((struct Obj00994 *)q)->f0,&a.x);
    ((struct Obj00994 *)q)->f4=func_02017270(((struct Obj00112 *)p)->f78,m,1,0xd8000,0x48000,0);
    func_02015FD4(*(char * *)&((struct Obj00994 *)q)->f4,2);
    func_02015D80(*(u8 * *)&((struct Obj00994 *)q)->f4,0xd555);
    func_02015D30(((struct Obj00994 *)q)->f4,&c.x);
    func_020173B4(((struct Obj00994 *)q)->f4);
    func_02015CDC(((struct Obj00994 *)q)->f4,&a.x);
    func_021D79A8((void *)p,q,0);
    func_021D7A1C((void *)p,q,&d);
    if(((struct Obj00994 *)q)->fC==1) {
        func_02015EB0(((struct Obj00994 *)q)->f0);
        func_02015EA0(((struct Obj00994 *)q)->f4);
        return;
    }
    func_02015EB0(((struct Obj00994 *)q)->f4);
    func_02015EA0(((struct Obj00994 *)q)->f0);
}
