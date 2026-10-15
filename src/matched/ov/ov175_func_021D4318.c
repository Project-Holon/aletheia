/*
 * function: func_021D4318
 * address: 0x021D4318
 * packet: pkt_ov175_021D4318
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0203159C's matched void body leaves allocated r0 live;
 *   caller captures r0 at 021D4348 as its cleared 0x100-byte buffer.
 * symbols:
 *   ov067_id 0x00000043 data
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E5440 0x021E5440 thumb ov177
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E567C 0x021E567C thumb ov177
 *   func_021D6698 0x021D6698 thumb ov175
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_Create 0x0201EC74 thumb
 *   func_021D9DC8 0x021D9DC8 thumb ov175
 *   func_021E8568 0x021E8568 thumb ov177
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_021D458C 0x021D458C thumb ov175
 *   func_021E7D20 0x021E7D20 thumb ov177
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_021D6524 0x021D6524 thumb ov175
 *   func_021D63C8 0x021D63C8 thumb ov175
 *   func_021DD008 0x021DD008 thumb ov175
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern const char ov067_id[], ov114_id[];
extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern int *func_021E5440(unsigned, int);
extern int func_021E5548(int *);
extern u32 *func_021E567C(int unused, int mode, int heap);
extern void func_021D6698(u32 *, u32 *);
struct GfFont;
struct MsgBank;
struct WordSet;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, unsigned short heap);
typedef unsigned short u16;
extern char *func_021D9DC8(u32 a, void *save, u32 b, u16 heap);
extern void *func_021E8568(unsigned, unsigned, unsigned, unsigned, void *, void *, unsigned);
extern int *func_021E8A3C(int, int, int);
extern void func_021D458C(unsigned sys, int *state, int *p);
extern void **func_021E7D20(void *, void *, unsigned);
extern void func_021E7E0C(void **, int);
extern void func_021D6524(int, int, u32);
extern void func_021D63C8(char *, u32);
extern void func_021DD008(char *, int);
int func_021D4318(void *sys, int *state, u32 *ctx)
{
    u32 *p;
    func_02034AC4((int)ov067_id);
    func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1, 87, 0x35000);
    p = PROCSYS_AllocProcWork(sys, 0x100, 87);
    MI_CpuFill8(p, 0, 0x100);
    p[16] = (u32)ctx;
    p[0] = (u32)func_021E5440(1, 87);
    p[1] = (u32)func_021E567C(func_021E5548((int *)p[0]), 2, 87);
    func_021D6698((u32 *)ctx[5], p);
    p[2] = (u32)GF_FONT_Create(23, 0, 0, 0, 87);
    p[3] = PRINTSYS_QUE_Create((void *)87);
    p[4] = (u32)func_02045B38(0, 2, 210, 87);
    p[5] = (u32)WORDSET_Create(8, 64, 87);
    p[12] = (u32)func_021D9DC8(((u32 *)p[16])[15], (void *)(((u32 *)ctx[2])[0]), ctx[7], 87);
    p[9] = (u32)func_021E8568(0, 15, 14, 10, (void *)p[3], (void *)p[2], 87);
    p[13] = (u32)func_021E8A3C((int)p, (int)func_021D458C, 87);
    p[14] = (u32)func_021E8A3C((int)p, 0, 87);
    p[8] = (u32)func_021E7D20((void *)func_021E5548((int *)p[0]), (void *)p[1], 87);
    func_021E7E0C((void **)p[8], 0);
    if (ctx[3] != 0) {
        if (ctx[0] == 0) {
            func_021D63C8((char *)p, 0);
        } else if (ctx[0] == 1) {
            if (ctx[3] == 1)
                func_021D6524(ctx[4], ((u32 *)ctx[2])[1], *(u32 *)ctx[11]);
            func_021D63C8((char *)p, 1);
        }
    }
    func_021DD008((char *)p[12], 1);
    return 1;
}
