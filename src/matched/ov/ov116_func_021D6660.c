/*
 * function: func_021D6660
 * address: 0x021D6660
 * packet: pkt_ov116_021D6660
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02012EF0 and 02012EFC lack an outside code witness.
 * blocker: 0x02012EF0 verified EXACT in 12EF0-r1.log (Thumb, dsi/1.1p1 -O4,p).
 *   extern int func_020071CC(void *,int);
 *   int GAME_DATA_GetSaveBlock3A(void **p) { return func_020071CC(*p,58); }
 * blocker: 0x02012EFC verified EXACT in 12EFC-r1.log (Thumb, dsi/1.1p1 -O4,p).
 *   extern int func_020071CC(void *,int);
 *   int GAME_DATA_GetSaveBlock3B(void **p) { return func_020071CC(*p,59); }
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   ov_id 0x00000072 data
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   GAME_DATA_GetSaveBlock3B 0x02012EFC thumb
 *   GAME_DATA_GetSaveBlock3A 0x02012EF0 thumb
 *   func_02008B08 0x02008B08 thumb
 *   func_021D6998 0x021D6998 thumb ov116
 *   func_021D6B50 0x021D6B50 thumb ov116
 *   func_021D70D8 0x021D70D8 thumb ov116
 */
typedef unsigned char u8;
extern u8 ov_id[];
typedef signed int     s32;
typedef unsigned int   u32;
struct Big;
struct BigObj;
struct Ctx;
struct Sub02008AECObj;
extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern u32 func_0201283C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern void *GAME_DATA_GetSaveBlock3B(void **p);
extern void *GAME_DATA_GetSaveBlock3A(void **p);
extern void func_021D6998(void *);
extern void func_021D6B50(unsigned char *a, int b);
extern void func_021D70D8(void *);
int func_021D6660(void *ctx,int unused,u8 *q) {
    u8 *p;
    void *save;
    func_02034AC4((s32)ov_id);
    func_0203064C(1,125,0x18000);
    p=func_0203159C(ctx,0x185c,125);
    func_02082BCC(p,0,0x185c);
    *(u8 **)p=q;
    *(int *)(q+8)=1;
    save=func_020120F4(*(void **)(*(u8 **)p+4));
    q=func_02012EBC(save);
    *(void **)(p+0x1844)=save;
    *(int *)(p+0x1848)=(int)func_02008B08(q);
    *(int *)(p+0x184c)=func_0201283C(save);
    *(int *)(p+0x1850)=(int)func_02012944(save);
    *(int *)(p+0x1854)=(int)GAME_DATA_GetSaveBlock3B(save);
    *(int *)(p+0x1858)=(int)GAME_DATA_GetSaveBlock3A(save);
    func_021D6998(p+0xb74);
    func_021D6B50(p+0x1610,125);
    func_021D70D8(p+0x182c);
    return 1;
}
