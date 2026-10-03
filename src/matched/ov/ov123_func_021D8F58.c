/*
 * function: func_021D8F58
 * address: 0x021D8F58
 * packet: pkt_ov123_021D8F58
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return.
 * symbols:
 *   func_02009290 0x02009290 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Sav;
struct Sub020075B0Entry;
struct Sub02009210Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int func_02009228(void *);
extern void func_02082D44(void *, void *, int);
extern void func_020307B0(void *);
extern u8 *func_02009290(struct Sub02009210Obj *obj);
extern void *func_020185F4(void *);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void func_02017528(struct Sav *p);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
void func_021D8F58(char *p)
{
    void *v;
    void *q;
    v=func_02009448(*(void **)(p+0x28));
    if (*(void **)(p+0x34)) {
        func_02082D44(*(void **)(p+0x34),v,func_02009228(*(void **)(p+0x34)));
        func_020307B0(*(void **)(p+0x34));
        *(void **)(p+0x34)=0;
    }
    if (*(u8 *)(p+0xaa)) {
        q=func_02009290(v);
        func_020075B0(*(void **)(p+0x24),*(int *)(p+0x48),*(int *)(p+0x4c),func_020185F4(q));
        func_02017528(q);
        func_020092F8(v,0);
        *(u8 *)(p+0xaa)=0;
    }
}
