/*
 * function: GDS_RAP_Init
 * address: 0x021D6660
 * packet: pkt_ov125_021D6660
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GDS_SOCKET_GetMaxReplySize 0x021D8600 arm ov125
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   GDS_SOCKET_Begin 0x021D8598 arm ov125
 *   func_02034714 0x02034714 arm
 *   ov114_id 0x00000072 data
 *   sGdsRapFileName 0x021D8D00 data a4
 *   sGdsServerHost 0x021D8D0C data a4
 *   sGdsEmptyString 0x021D8D28 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[7]; } Blk;
typedef signed int     s32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern int func_02034AC4(s32 handle);
extern void MI_CpuFill8(void *, int, u32);
extern int GDS_SOCKET_GetMaxReplySize(int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern int GDS_SOCKET_Begin(void *, const char *, int);
extern void func_02034714(const char *, u32, const char *);
extern char ov114_id[];
extern const char sGdsRapFileName[];
extern const char sGdsServerHost[];
extern char sGdsEmptyString[];

int GDS_RAP_Init(char *p, char *a)
{
    func_02034AC4((int)ov114_id);
    MI_CpuFill8(p, 0, 0x5A4);
    *(u32 *)(p + 0x13C) = *(u16 *)(a + 4);
    *(u32 *)p = *(u32 *)(a + 8);
    *(u32 *)(p + 0x494) = *(u32 *)(a + 0xC);
    *(Blk *)(p + 0x148) = *(Blk *)(a + 0x10);
    *(int *)(p + 0x144) = -1;
    *(u32 *)(p + 0x3D8) = 0x55F4;
    *(u32 *)(p + 0x3DC) = 0x55F4;
    *(void **)(p + 0x3AC) = func_02030734(*(u16 *)(a + 4), GDS_SOCKET_GetMaxReplySize(-1), 0, sGdsRapFileName, 0x84);
    MI_CpuFill8(*(void **)(p + 0x3AC), 0, GDS_SOCKET_GetMaxReplySize(-1));
    *(int *)(p + 0x3E4) = (int)func_02045B38(0, 2, 0xE8, *(u16 *)(a + 4));
    *(int *)(p + 0x3E8) = (int)func_0201EC64(*(u16 *)(a + 4));
    *(int *)(p + 0x3EC) = (int)STRBUF_Create(0x100, *(u16 *)(a + 4));
    *(u32 *)(p + 4) = *(u32 *)a;
    p[8] = 0x15;
    p[9] = 2;
    if (GDS_SOCKET_Begin(p + 4, sGdsServerHost, 0x3071) != 1)
        func_02034714(sGdsEmptyString, 0, sGdsEmptyString);
    *(u32 *)(p + 0x3B4) = 1;
    *(u32 *)(p + 0x3B0) = 1;
    return 1;
}
