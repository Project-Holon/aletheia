/*
 * function: BR_BTN_Create
 * address: 0x021F9CB8
 * packet: pkt_ov186_021F9CB8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BR_BTN_DATA_Create 0x021FB5E4 thumb ov186
 *   BR_BTN_DATA_GetMaxSectionCount 0x021FB788 thumb ov186
 *   BR_BTN_DATA_GetSectionCount 0x021FB760 thumb ov186
 *   BR_BTN_DATA_GetRow 0x021FB704 thumb ov186
 *   BR_BTN_DATA_CreateLabel 0x021FB7D0 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_BTN_InitRecord 0x021FAC20 thumb ov186
 *   BR_BTN_PushRecord 0x021FA020 thumb ov186
 *   BR_BTN_PlaceIndexed 0x021FAEC0 thumb ov186
 *   BR_BTN_SetPosY 0x021FAF08 thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_BTN_SetupInput 0x021FA274 thumb ov186
 *   BR_BTN_UpdateCollapse 0x021FA920 thumb ov186
 *   BR_BTN_UpdateSlide 0x021FAAD0 thumb ov186
 *   d_02200D18 0x02200D18 data a1
 *   d_02200D1C 0x02200D1C data a1
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Rec { u16 a, b; };
struct Set { struct Rec rec[6]; u32 count; };
struct Obj {
    u16 heap;
    u16 pad0;
    int f4;
    int f8;
    int *fC;
    int f10;
    int f14;
    int pad18;
    int f1C;
    int pad20[6];
    u8 f38;
    u8 f39;
    u8 f3a;
    u8 f3b;
    char *f3c;
    char *f40;
    void *f44;
    void *f48;
    u32 f4c;
    int pad50[2];
    int f58;
    struct Set *f5c;
};
extern char d_02200D18[];
extern char d_02200D1C[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, int);
struct U16Vec;
extern void *BMP_OAM_CreateSys(u32 a0, void *a1);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BR_BTN_DATA_Create(int *ctx, int heap);
extern unsigned BR_BTN_DATA_GetMaxSectionCount(void *);
extern unsigned short BR_BTN_DATA_GetSectionCount(void *, int);
extern void *BR_BTN_DATA_GetRow(char *ctx, int section, unsigned item);
struct MsgBank;
extern void *BR_BTN_DATA_CreateLabel(unsigned * const *p, void *record, struct MsgBank *archive, unsigned short heap);
extern void BR_RES_LoadSprite(char *base, u32 idx, u32 area);
extern void BR_BTN_InitRecord(void *ctx, void *object, int a, void *b, int owner, void *arg, int index, u32 heap);
extern void BR_BTN_PushRecord(u8 *ctx, int a1, int a2);
extern void BR_BTN_PlaceIndexed(char *p, unsigned index);
extern void BR_BTN_SetPosY(char *p, int a1);
extern int BR_RES_GetMsgData(char *p);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_SetupInput(void *p);
extern void BR_BTN_UpdateCollapse(int *task, int *state, u8 *ctx);
extern void BR_BTN_UpdateSlide(void *p, int *state, unsigned char *ctx);
struct Obj *BR_BTN_Create(int a, int b, int c, int d, int e, int f, u32 heap)
{
    struct Obj *p;
    int tmp;
    int size;
    int i;
    int arch;
    u8 buf[0x44];
    if (a >= 12) func_02034714(d_02200D18, 0, d_02200D18);
    p = func_02030734(heap, 0x60, 0, d_02200D1C, 0x13F);
    MI_CpuFill8(p, 0, 0x60);
    p->f4 = c;
    p->f8 = b;
    p->heap = heap;
    p->f5c = (struct Set *)e;
    p->f48 = BMP_OAM_CreateSys(heap, (void *)b);
    p->f4c = PRINTSYS_QUE_Create((void *)heap);
    p->f58 = f;
    p->f14 = 1;
    MI_CpuFill8(&tmp, 0, 4);
    tmp = d;
    p->f44 = BR_BTN_DATA_Create(&tmp, heap);
    if (a >= 10) p->f10 = 2;
    else p->f10 = 0;
    BR_RES_LoadSprite((char *)p->f4, p->f10, heap);
    BR_RES_LoadSprite((char *)p->f4, p->f10 + 1, heap);
    p->f38 = BR_BTN_DATA_GetMaxSectionCount(p->f44);
    size = p->f38 * 0x44;
    p->f40 = func_02030734(heap, size, 0, d_02200D1C, 0x167);
    MI_CpuFill8(p->f40, 0, size);
    p->f3a = 6;
    p->f3c = func_02030734(heap, 0x198, 0, d_02200D1C, 0x171);
    MI_CpuFill8(p->f3c, 0, 0x198);
    p->fC = BR_UTIL_CreateTask((int)p, (int)BR_BTN_SetupInput, heap);
    if (p->f5c->count != 0) {
        arch = BR_RES_GetMsgData((char *)c);
        for (i = 0; i < p->f5c->count; i++) {
            void *q = BR_BTN_DATA_GetRow(p->f44, p->f5c->rec[i].a, (unsigned short)p->f5c->rec[i].b);
            void *rec = BR_BTN_DATA_CreateLabel(p->f44, q, (struct MsgBank *)arch, (heap & 0x7FFF) | 0x8000);
            MI_CpuFill8(buf, 0, 0x44);
            BR_BTN_InitRecord(buf, q, b, p->f48, c, rec, p->f10, heap);
            BR_BTN_PushRecord((u8 *)p, (int)buf, 0);
            STRBUF_Delete(rec);
        }
        for (i = 0; i < p->f3b; i++)
            BR_BTN_PlaceIndexed(p->f3c + (p->f3b - i - 1) * 0x44, (unsigned short)i);
        BR_UTIL_SetTaskStep(p->fC, (int)BR_BTN_UpdateCollapse);
        p->f1C = 2;
    } else {
        arch = BR_RES_GetMsgData((char *)c);
        p->f39 = BR_BTN_DATA_GetSectionCount(p->f44, a);
        for (i = 0; i < p->f39; i++) {
            void *q = BR_BTN_DATA_GetRow(p->f44, a, (unsigned short)i);
            void *rec = BR_BTN_DATA_CreateLabel(p->f44, q, (struct MsgBank *)arch, (heap & 0x7FFF) | 0x8000);
            BR_BTN_InitRecord(p->f40 + i * 0x44, q, b, p->f48, c, rec, p->f10, heap);
            STRBUF_Delete(rec);
        }
        for (i = 0; i < p->f39; i++)
            BR_BTN_SetPosY(p->f40 + i * 0x44, 0xe0);
        BR_UTIL_SetTaskStep(p->fC, (int)BR_BTN_UpdateSlide);
    }
    return p;
}
