/*
 * function: func_021DB508
 * address: 0x021DB508
 * packet: pkt_ov131_021DB508
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: the final two bytes at 021DB612 are zero alignment padding.
 * semantic: selectors and slot indices preserve every input word. Selector
 *   additions and index*24/address additions are u32 wrap, with pointer
 *   conversion only after address arithmetic; no asserted slot bound.
 *   Six getter results and four selectors are assigned before use.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`apid=a;` before `apid=a+58U;`; `auid=a;` before `auid=a+62U;` and 2
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D60D4 0x021D60D4 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_020181FC 0x020181FC thumb
 *   func_02017E64 0x02017E64 thumb
 *   func_021DBE98 0x021DBE98 thumb ov131
 *   func_021D9EE8 0x021D9EE8 thumb ov131
 */
#include "../include/Obj23171.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D6064(u8 *);
extern void func_021D60D4(u8 *,int);
extern u32 func_02017E88(void *,u32,u32);
extern void func_020181FC(void *,u16,u32);
extern void func_02017E64(void *,u32,u32);
extern void func_021DBE98(int *a, int *b);
extern void func_021D9EE8(u8 *,u8 *);
void func_021DB508(u8 *p,u8 *q,u32 a,u32 b)
{
    void *m;
    u32 am,app,au,bm,bpp,bu;
    u32 apid,auid,bpid,buid;
    m=func_021D6064(p);
    func_021D60D4(p,1);
    am=func_02017E88(m,a+54U,0);
    apid=a+58U;
    app=func_02017E88(m,apid,0);
    auid=a+62U;
    au=func_02017E88(m,auid,0);
    bm=func_02017E88(m,b+54U,0);
    bpid=b+58U;
    bpp=func_02017E88(m,bpid,0);
    buid=b+62U;
    bu=func_02017E88(m,buid,0);
    func_020181FC(m,bm,a);
    func_020181FC(m,am,b);
    func_02017E64(m,apid,bpp);
    func_02017E64(m,auid,bu);
    func_02017E64(m,bpid,app);
    func_02017E64(m,buid,au);
    func_021D60D4(p,0);
    func_021DBE98(*(void **)((u32)q+a*24U+196U),*(void **)((u32)q+b*24U+196U));
    *(u32 *)((u32)q+a*24U+180U)=1;
    *(u32 *)((u32)q+b*24U+180U)=1;
    func_021D9EE8(p,q);
    ((struct Obj23171 *)q)->f10=1;
}
