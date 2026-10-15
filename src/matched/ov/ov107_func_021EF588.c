/*
 * function: MB_COMM_SYS_BuildGameStrings
 * address: 0x021EF588
 * packet: pkt_ov107_021EF588
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (integrator): the fullwidth-to-ASCII constants are plain literals (0xFF29, 0xFF24, 0xFF10..0xFF19, c - 0xFEE0); mwcc derives them from one held value itself, so the earlier `u32 k = 0xFF24` local was not needed. EXACT in c99 and c.
 * symbols:
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02030734 0x02030734 arm
 *   MB_UTIL_MSG_SetWindowLayout 0x021F1628 thumb ov107
 *   MB_UTIL_MSG_CreateWordSet 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   MB_UTIL_MSG_SetNumberZeroPad 0x021F1918 thumb ov107
 *   MB_UTIL_MSG_GetMsgData 0x021F1AFC thumb ov107
 *   MB_UTIL_MSG_GetWordSet 0x021F1B00 thumb ov107
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02040588 0x02040588 arm
 *   CARD_SetPulledOutCallback 0x020774A0 arm
 *   MB_COMM_SYS_ShowTextPlane 0x021F05DC thumb ov107
 *   d_021F6E0C 0x021F6E0C data a4
 *   ov014_id 0x0000000E data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub0200852CObj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Work {
    u16 f0;
    u8 pad_2[6];
    u8 **f8;
    u8 pad_c[0x18];
    u8 f24;
    u8 pad_25;
    u8 f26;
    u8 pad_27;
    u8 f28;
    u8 pad_29[7];
    int f30;
    u8 pad_34[0x1c];
    u16 *f50;
    u16 *f54;
    u8 pad_58[0x10];
    u8 *f68;
};
extern const char d_021F6E0C[];
extern u8 ov014_id[];
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void MB_UTIL_MSG_SetWindowLayout(void *, int), MB_UTIL_MSG_CreateWordSet(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void MB_UTIL_MSG_SetNumberZeroPad(unsigned char *a, int b, int c, int d);
extern u32 MB_UTIL_MSG_GetMsgData(u8 *p);
extern u32 MB_UTIL_MSG_GetWordSet(u8 *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef signed int     s32;
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void MIi_CpuCopy16(const void *, void *, int);
extern int func_02034AC4(s32 handle);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void CARD_SetPulledOutCallback(int (*callback)(void));
extern int MB_COMM_SYS_ShowTextPlane(void);

void MB_COMM_SYS_BuildGameStrings(u8 *p)
{
    struct Work *w = (struct Work *)p;
    u8 *q;
    struct U16Vec *a;
    struct U16Vec *b;
    void *m;
    u16 la;
    u16 lb;
    int i;
    u16 *dst;
    u16 *src;


    q = GAME_DATA_GetMyStatus(w->f8[1]);
    w->f24 = 0;
    w->f26 = 0;
    w->f50 = func_02030734(w->f0, 0x60, 1, d_021F6E0C, 0x553);
    w->f54 = func_02030734(w->f0, 0xC0, 1, d_021F6E0C, 0x554);
    MB_UTIL_MSG_SetWindowLayout(w->f68, 1);
    MB_UTIL_MSG_CreateWordSet(w->f68);
    MB_UTIL_MSG_SetNumberZeroPad(w->f68, 0, func_02008534((const struct Sub0200852CObj *)q), 5);
    if (w->f28 == 0)
        m = func_02045EC0((struct MsgBank *)MB_UTIL_MSG_GetMsgData(w->f68), 0xC);
    else
        m = func_02045EC0((struct MsgBank *)MB_UTIL_MSG_GetMsgData(w->f68), 0xF);
    a = STRBUF_Create(0x100, w->f0);
    WORDSET_CopyTaggedText((struct WordSet *)MB_UTIL_MSG_GetWordSet(w->f68), a, m);
    STRBUF_Delete((struct U16Vec *)m);
    if (w->f28 == 0)
        m = func_02045EC0((struct MsgBank *)MB_UTIL_MSG_GetMsgData(w->f68), 0xD);
    else
        m = func_02045EC0((struct MsgBank *)MB_UTIL_MSG_GetMsgData(w->f68), 0x10);
    b = (struct U16Vec *)m;
    la = (u32)STRBUF_GetLength(a);
    lb = (u32)STRBUF_GetLength(b);
    dst = w->f50;
    src = STRBUF_GetChars(a);
    MIi_CpuCopy16(src, dst, la * 2);
    dst = w->f54;
    src = STRBUF_GetChars(b);
    MIi_CpuCopy16(src, dst, lb * 2);
    STRBUF_Delete(a);
    STRBUF_Delete(b);
    w->f50[la] = 0;
    w->f54[lb] = 0;
    for (i = 0; i < 0x60; i++) {
        if (w->f54[i] == 0xFFFE)
            w->f54[i] = 0xA;
    }
    for (i = 0; i < 0x30; i++) {
        u16 c = w->f50[i];
        if (c == 0xFF29)
            w->f50[i] = 0x49;
        else if (c == 0xFF24)
            w->f50[i] = 0x44;
        else if (c >= 0xFF10 && c <= 0xFF19)
            w->f50[i] = c - 0xFEE0;
    }
    w->f30 = 0;
    func_02034AC4((int)ov014_id);
    if (w->f28 == 0) {
        func_02040588(2, 1);
        func_02040588(0, 1);
    } else {
        func_02040588(5, 1);
        func_02040588(4, 1);
    }
    CARD_SetPulledOutCallback(MB_COMM_SYS_ShowTextPlane);
}
