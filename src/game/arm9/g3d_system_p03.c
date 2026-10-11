/*
 * file:     g3d_system_p03.c
 * unit:     yes
 * function: func_02048C58, func_02048C80, func_02048CA4, func_02048CCC, func_02048CDC, func_02048CEC, func_02048D00, func_02048D54, func_02048DDC, func_02048E34, func_02048F4C, func_02048F60, func_02048F74, func_02048F88, func_02048F9C, func_02049030, func_020490A8, sub_020490F4, func_0204913C, func_0204919C, func_02049238, func_02049250, func_0204932C, func_020493D4, func_0204944C, func_020494F4, func_02049578, func_020495F4, NHTTPi_GetConnection, func_0204961C, func_02049624, sub_02049658, sub_0204968C, sub_020496E4, sub_02049740, sub_0204979C, sub_02049800, sub_0204982C, sub_0204989C, sub_020498F4, func_0204994C, func_02049990, func_020499D4, func_02049A18, sub_02049B40, sub_02049B68, func_02049B90, func_02049BDC, func_02049C28, func_02049DB4, func_02049DF4, func_02049E34, func_02049E74, func_02049EB4, func_02049EF4, func_02049F34, func_02049F78, func_02049FBC, func_02049FFC, func_0204A03C, func_0204A07C, func_0204A0BC, func_0204A0FC, func_0204A13C, func_0204A17C, func_0204A1BC, func_0204A298, func_0204A380, func_0204A39C
 * address:  0x02048C58
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02046A94  0x02046A94  arm
 *   g_02146A68     0x02146A68  data
 *   func_02078A80  0x02078A80  arm
 *   func_02078B70  0x02078B70  arm
 *   func_02048D54_File  0x020A7EE0  data
 *   func_02030734       0x02030734  arm
 *   FS_InitFile             0x020788AC  arm
 *   CRYPTOi__BN_lshift1     0x02078C18  arm
 *   FS_CreateFileFromMemory 0x0207A940  arm
 *   FS_SeekFile             0x02078B44  arm
 *   FS_ReadFile             0x02078B70  arm
 *   func_02034734           0x02034734  arm
 *   func_02048DDC_File      0x020A7EE0  data
 *   func_02048DDC_Msg       0x020A7EEC  data
 *   func_02048F9C_File 0x020A7EE0  data
 *   func_02078B44  0x02078B44  arm
 *   sub_020490F4_File  0x020A7EE0  data
 *   func_0204913C_File      0x020A7EE0  data
 *   func_020307B0 0x020307B0 arm
 *   func_02049250_File 0x020A7EE0  data
 *   func_02049250_Msg  0x020A7F18  data
 *   func_0204932C_File 0x020A7EE0  data
 *   func_0204932C_Msg  0x020A7F18  data
 *   func_020493D4_File 0x020A7EE0  data
 *   func_020493D4_Msg  0x020A7F18  data
 *   func_0204944C_File 0x020A7EE0  data
 *   func_0204944C_Msg  0x020A7F18  data
 *   func_020494F4_File 0x020A7EE0  data
 *   func_020494F4_Msg  0x020A7F18  data
 *   func_02049578_File 0x020A7EE0  data
 *   func_02049578_Msg  0x020A7F18  data
 *   func_0204968C  0x0204968C  arm
 *   sub_0204A380   0x0204A380  arm
 *   func_02062A4C       0x02062A4C  arm
 *   func_02040B1C       0x02040B1C  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_0204979C       0x0204979C  arm
 *   func_02040B58  0x02040B58  arm
 *   func_0204982C  0x0204982C  arm
 *   func_02062A00       0x02062A00  arm
 *   DC_FlushRange       0x020862F0  arm
 *   g_020A135C          0x020A135C  data
 *   sub_02049A18   0x02049A18  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02040AF0  0x02040AF0  arm
 *   func_020409E0  0x020409E0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 *   sub_02049B90   0x02049B90  arm
 *   sub_02049BDC   0x02049BDC  arm
 *   g_020A1364     0x020A1364  data
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207F308  0x0207F308  arm
 *   func_0207F428  0x0207F428  arm
 *   func_0207F5B0  0x0207F5B0  arm
 *   func_0207F65C  0x0207F65C  arm
 *   func_0207F47C  0x0207F47C  arm
 *   func_0207F560  0x0207F560  arm
 *   func_0207F6A8  0x0207F6A8  arm
 *   func_0207F754  0x0207F754  arm
 *   func_02062820  0x02062820  arm
 *   func_02062670  0x02062670  arm
 *   func_02062920  0x02062920  arm
 *   func_0206267C  0x0206267C  arm
 *   func_020834C0  0x020834C0  arm
 *   sArcUtil3730   0x020A7F30  data
 *   MI_UncompressLZ8 0x020834C0 arm
 *   lbl_020A7F30     0x020A7F30 data
 */
#include "../../matched/include/Obj05745.h"
#include "../../matched/include/Obj08859.h"
#include "../../matched/include/Obj17354.h"
#include "../../matched/include/Obj16074.h"
#include "../../matched/include/Obj16075.h"
#include "../../matched/include/Obj16076.h"

struct ArcFile;
struct FSFile;
struct ArcHandle;
struct NitroFileHeader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Rgb555 {
    u16 r;
    u16 g;
    u16 b;
};

struct LightSlot {
    struct Rgb555 col;
    u16           unk06;
};

struct LightGlobal {
    u32 * volatile unk00;
    u32            unk04;
    u32            unk08;
};

struct ArcFile {
    u8 file[0x48];
};

struct ArcHandle {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

typedef signed int     s32;

struct ArcRecord {
    u32          start;
    volatile u32 end;
};

struct FatInfo {
    u32 offset;
    u16 count;
};

struct ArcFile_02049250 {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_0204932C {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_020493D4 {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_0204944C {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_020494F4 {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_02049578 {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

struct ArcFile_020495F4 {
    u8 raw[0x50];
};

struct Res {
    u8 pad_00[0x10];
    u32 unk_10;
    u32 unk_14;
};

struct Pal {
    u8  pad00[8];
    u32 size;
    u8  data[1];
};

struct Pltt {
    u32 fmt;
    u8  pad04[4];
    u32 size;
    u32 data;
};

typedef void (*LoadFn)(u32 data, u32 dest, u32 size);

extern void func_02046A94(u32 idx, const u16 *src);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void func_02078A80(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FS_InitFile(void *file);
extern void CRYPTOi__BN_lshift1(struct ArcFile *arc, u32 value);
extern void FS_CreateFileFromMemory(void *file, void *src, u32 size);
extern void FS_SeekFile(struct ArcHandle *arc, u32 pos, u32 origin);
extern void FS_ReadFile(struct ArcHandle *arc, void *dst, u32 size);
extern void func_02034734(const char *file, u32 line, const char *msg, ...);
extern void func_020788AC(struct ArcFile *f);
extern void func_02078C18(struct ArcFile *f, const char *path);
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern u32 func_020307B0(void *p);
extern u32 func_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused);
extern void *sub_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void ENV_SetResourceSet(void *p);
extern u32 func_0204979C(void *buf, u32 a1, u32 a2);
extern u32 func_02040B58(u32 index, const void *src, u32 size);
extern u32 func_0204982C(void *buf, u32 kind, u32 a2, u32 size);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void DC_FlushRange(u32 addr, u32 size);
extern u32 sub_02049A18(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020409B4(u8 channel);
extern void func_02041B6C(u8 channel);
extern void sub_02049B90(u32 a, u32 b, u32 c, u32 zero, u32 d, u32 e, u16 f);
extern void sub_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_020862F0(u32 addr, u32 size);
extern void func_0207F308(void);
extern void func_0207F428(void);
extern void func_0207F5B0(void);
extern void func_0207F65C(void);
extern void func_0207F47C(void);
extern void func_0207F560(void);
extern void func_0207F6A8(void);
extern void func_0207F754(void);
extern int func_02062820(int a, int *out);
extern int   func_02062670(void *ptr, u32 val);
extern int func_02062920(u32 a, u32 *out);
extern int   func_0206267C(void *ptr, u32 val);
extern int         func_020834C0(int a0, int a1);
extern void MI_UncompressLZ8(const void *src, void *dest);
void func_02048C58(struct LightSlot *slots);
void func_02048C80(struct LightSlot *slots, u8 i, struct Rgb555 *out);
void func_02048CA4(struct LightSlot *slots, u32 i, struct Rgb555 *in);
void func_02048CCC(struct LightSlot *slots, u8 i, u16 *out);
void func_02048CDC(struct LightSlot *slots, u32 i, u16 *in);
void func_02048CEC(u32 a, u32 b);
void func_02048D00(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
void *func_02048D54(u32 archive_id, u32 member, u32 heap, u32 mode, u32 *size_out);
void func_02048DDC(struct ArcFile *arc, u32 id);
u32 func_02048E34(struct ArcHandle *arc, u32 member, u32 base, u32 size);
void func_02048F4C(void *dst, u32 archive_id, u32 member);
void *func_02048F60(u32 archive_id, u32 member, u32 heap);
void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode, u32 *size_out);
void *func_02048F9C(const char *path, u32 a, u32 heap);
u32 func_02049030(u32 a);
u32 func_020490A8(u32 a, u32 b);
void *sub_020490F4(u32 id, u32 heap);
void *func_0204913C(void *a0, u32 a1, u32 heap);
void func_0204919C(u8 *p);
asm void func_02049238(void *arc);
void *func_02049250(struct ArcFile_02049250 *arc, u32 member, u32 heap);
void func_0204932C(struct ArcFile_0204932C *arc, u32 member, void *dst);
u32 func_020493D4(struct ArcFile_020493D4 *arc, u32 member);
void func_0204944C(struct ArcFile_0204944C *arc, u32 member, u32 offset, u32 size, void *dst);
void func_020494F4(struct ArcFile_020494F4 *arc, u32 member, u32 *out);
u32 func_02049578(struct ArcFile_02049578 *arc, u32 member);
void func_020495F4(struct ArcFile_020495F4 *arc, u32 size, void *dst);
asm void NHTTPi_GetConnection(void);
u16 func_0204961C(void *obj);
u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
u32 sub_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
u32 sub_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused);
u32 sub_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
u32 sub_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
u32 sub_0204979C(void *buf, u32 a1, u32 a2);
u32 sub_02049800(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
u32 sub_0204982C(void *buf, u32 kind, u32 a2, u32 size);
void sub_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
void sub_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
u32 func_02049A18(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);
void sub_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void sub_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
void func_02049C28(void *file, u32 kind, u32 offset, u32 dest, u32 size);
void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049EF4(void *a0, u32 a1, u32 a2, void **out, u16 a4);
void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
void *func_02049FBC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_02049FFC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A03C(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A07C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A0BC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A0FC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A13C(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void *func_0204A17C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
int func_0204A1BC(int a0, int a1, int a2, int a3);
int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern struct LightGlobal g_02146A68;
extern const char func_02048D54_File[];
extern const char func_02048DDC_File[];
extern const char func_02048DDC_Msg[];
extern const char func_02048F9C_File[];
extern const char sub_020490F4_File[];
extern const char func_0204913C_File[];
extern const char func_02049250_File[];
extern const char func_02049250_Msg[];
extern const char func_0204932C_File[];
extern const char func_0204932C_Msg[];
extern const char func_020493D4_File[];
extern const char func_020493D4_Msg[];
extern const char func_0204944C_File[];
extern const char func_0204944C_Msg[];
extern const char func_020494F4_File[];
extern const char func_020494F4_Msg[];
extern const char func_02049578_File[];
extern const char func_02049578_Msg[];
extern const LoadFn g_020A1364[];
extern const char  sArcUtil3730[];
extern const char lbl_020A7F30[];








/*
 * g3d_light.c's tail, 0x02048C58-0x02048D00: the four-slot upload loop and
 * the per-slot colour accessors over the same eight-byte slot the builder at
 * 0x02048BC4 fills, three halfwords of colour and one spare.
 *
 *   0x02048C58  push all four slots through 0x02046A94; the `and r0, #0xff`
 *               on the loop counter is the callee's `u8` first parameter,
 *               not a narrow counter (the counter itself increments and
 *               compares as a plain `int`)
 *   0x02048C80  read slot i's colour out, 0x02048CA4 writes it
 *   0x02048CCC  read slot i's spare halfword out, 0x02048CDC writes it
 *   0x02048CEC  seed the three-word global at 0x02146A68 from two arguments
 *               and a zero
 *
 * 0x02048CA4 pushes {r3, lr} and calls nothing: lr is spilled purely as a
 * scratch register for the third halfword of the copy.  Its source pointer
 * must not be `const`: with `const` mwcc proves the two halfword stores
 * cannot reach the source and hoists all three loads ahead of them, which is
 * thirteen bytes wrong; without it the third load stays after the first two
 * stores, in source order.
 *
 * The six-byte colour moves are aggregate assignments of the nested struct,
 * which is why the loads pair up ahead of the stores rather than
 * interleaving one field at a time
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md, halfword form).
 *
 * The unit starts at 0x02048C58 and not earlier because 0x02048C4C holds an
 * ARM long-branch veneer that no `tu` range may span.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048C58.c \
 *       --addr 0x02048C58 --cc 1.1p1 --arm
 */
void func_02048C58(struct LightSlot *slots)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02046A94((u8)i, (const u16 *)(&slots[i]));
    }
}








void func_02048C80(struct LightSlot *slots, u8 i, struct Rgb555 *out)
{
    *out = slots[i].col;
}








void func_02048CA4(struct LightSlot *slots, u32 i, struct Rgb555 *in)
{
    slots[i].col = *in;
}








void func_02048CCC(struct LightSlot *slots, u8 i, u16 *out)
{
    *out = slots[i].unk06;
}








void func_02048CDC(struct LightSlot *slots, u32 i, u16 *in)
{
    slots[i].unk06 = *in;
}








void func_02048CEC(u32 a, u32 b)
{
    g_02146A68.unk00 = (u32 *)a;
    g_02146A68.unk04 = b;
    g_02146A68.unk08 = 0;
}









/*
 * Read one sub-file of one archive into a buffer the caller owns.  The whole
 * archive handle is a 0x48 byte stack local: func_02048DDC binds it to the
 * archive named by `archive_id` (it indexes the 235-entry a/x/y/z name table
 * at 0x020A6C58), func_02048E34 seeks the member and returns its byte size,
 * func_02078B70 is the read and func_02078A80 closes the handle again.
 *
 * Nothing survives the call, so this is the one-shot form: a caller that wants
 * the archive to stay open uses func_020490F4 instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048D00.c \
 *       --func func_02048D00 --addr 0x02048D00 --cc 1.1p1 --arm
 */
void func_02048D00(void *dst, u32 archive_id, u32 member, u32 mode,
                   u32 *size_out)
{
    struct ArcFile h;

    func_02048DDC(&h, archive_id);
    func_02078B70((struct FSFile *)(&h), dst, func_02048E34((struct ArcHandle *)&h, member, mode, (u32)size_out));
    func_02078A80(&h);
}









/*
 * The allocating twin of func_02048D00: bind a temporary 0x48-byte archive
 * handle to `archive_id`, size the member, take a block of exactly that size
 * from the caller's heap, read the member into it, close the handle and hand
 * the block back.  The __FILE__ argument is "arc_tool.c" at 0x020A7EE0, the
 * same string src/matched/sub_020490F4.c already pins, with line 0xbb.
 *
 * This is the function the whole map-model path goes through: func_02048F60
 * calls it as func_02048D54(9, matrix_id, heap, 0, NULL), and ov010's
 * func_02159B94 is what supplies archive id 9 (a/0/0/9) and the matrix id
 * read out of the zone record's +0x04 lane.  See docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048D54.c \
 *       --func func_02048D54 --addr 0x02048D54 --cc 1.1p1 --arm
 */
void *func_02048D54(u32 archive_id, u32 member, u32 heap, u32 mode,
                    u32 *size_out)
{
    struct ArcFile h;
    u32 size;
    void *buf;

    func_02048DDC(&h, archive_id);
    size = func_02048E34((struct ArcHandle *)&h, member, mode, (u32)size_out);
    buf = func_02030734(heap, size, 0, func_02048D54_File, 0xbb);
    func_02078B70((struct FSFile *)(&h), buf, size);
    func_02078A80(&h);
    return buf;
}








/*
 * The whole of packet pkt_02048DDC, 0x02048DDC-0x02048F4C: arc_tool.c's
 * archive binder (func_02048DDC) and the member resolver it hands off to
 * (func_02048E34), both open functions on the eidos port's blocked list.
 * Verified as one translation unit, so the literal pool at 0x02048E30
 * between the two functions and the two pool words at 0x02048F44/0x02048F48
 * are inside the compared range: 2 sections, 368 bytes, no padding, 16 of 16
 * relocation sites resolved (attestation classes: label for the five SDK
 * entry points and func_02034734, literal for g_02146A68 and the arc_tool.c
 * string, string for the assertion text).
 *
 * ---------------------------------------------------------------------------
 * func_02048DDC - "open archive by id"
 *
 * FS_InitFile binds the caller's 0x48-byte handle, then the one global at
 * 0x02146A68 picks the archive's storage: with its +0x08 flag clear the
 * +0x00 pointer is the 235-entry name table (installed by
 * func_02048CEC(0x020A6C58, 0xeb), see docs/ASSETS.md) and the member's name
 * is opened by path; with the flag set the same table is an array of 8-byte
 * {start, end} extents and the member is bound straight out of memory as
 * (start, end - start).  Nothing in the image ever sets +0x08, so the second
 * arm is dead code kept for the id-as-pointer build.
 *
 * The two arms must each read the +0x00 table pointer themselves: the
 * original spends a separate `ldr` in each arm and the record arm's pointer
 * lands in r3.  Three things in this spelling are shape, not semantics, and
 * each is load-bearing for -O4,p at 1.1p1 - each was measured against a
 * variant that differs only in the qualifier or the declaration:
 *
 *   - `u32 * volatile unk00`: without `volatile` the optimizer
 *     common-subexpresses the two arms' table-pointer loads, hoists the one
 *     load above the `bne` (the word arm then begins with `mov r0, r5` at
 *     +0x20 instead of +0x24) and the record arm reuses it.  A volatile load
 *     cannot be CSE'd, so each arm reloads, and the function is 88 bytes
 *     instead of 76.
 *   - `volatile u32 end` in the extent type: without it mwcc merges the
 *     record's two field loads into `ldm r2, {r1, r2}`, which is four bytes
 *     short and re-tiles the low word onto the materialised address.
 *   - `u32 *tbl` bound before the record pointer: with the pointer expression
 *     inlined into the subscript
 *     (`(struct ArcRecord *)g_02146A68.unk00 + id`) the same code comes out
 *     with the table in r1 and the materialised address in r2, i.e. every
 *     register in the record arm is off by one slot.  Naming the loaded table
 *     first makes mwcc keep it in r3 and use r1 for the address, as the
 *     original does.
 *
 * The 8-byte extent is {start, end} and the requested length is end - start;
 * the two locals mirror the original's evaluation order, which loads the high
 * word first.  A plain `u32 *` (or a plain `u32` plus a cast in the word arm)
 * instead of `u32 * volatile` is 76-84 bytes, never 88.  The sibling unit
 * src/matched/unit_02048C58.c declares the same global as three plain u32
 * fields, which is right for what it does (func_02048CEC writes it) and is
 * not enough for this reader.  See docs/notes/pkt_02048DDC.c.txt.
 *
 * ---------------------------------------------------------------------------
 * func_02048E34 - resolve one member's extent
 *
 * Read the FAT offset out of the file header at +0xc, read the tail of the
 * table it points to ({u32 image delta, u16 count} at fatOffset+4), range
 * check the member index, walk to the member's {u32 start, u32 end} pair at
 * fatOffset+0xc+member*8 and seek to its first byte at base+image+8+start.
 * Returns the member's byte length, or `size` when the caller supplied one
 * (that is the `size_out` argument the sibling readers in src/matched/ pass
 * as 0).  The u32 at +4 doubles as the scratch the first two reads share,
 * which is why it is zeroed before the 2-byte read: the top half of the
 * u32 stays clear.
 *
 * The assertion's variadic tail is two values, the count and the member: r3
 * is never written on the assert path, so the `ldrh` that fed the guard's
 * `cmp` is still live and only the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 * 0x020A7EE0 is the arc_tool.c anchor src/matched/func_02048D54.c already
 * pins; 0x020A7EEC is the assertion text, fixed from outside by the
 * terminator of the string in front of it.  The `ldreq`/`subeq` tail is
 * "take the caller's size if it is non-zero, else end - start".
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048DDC.c \
 *       --addr 0x02048DDC --cc 1.1p1 --arm
 * (both halves were also verified individually as `one` before folding them
 * into this unit: func_02048DDC 88 bytes, func_02048E34 280 bytes.)
 */
void func_02048DDC(struct ArcFile *arc, u32 id)
{
    FS_InitFile(arc);
    if (g_02146A68.unk08 == 0) {
        CRYPTOi__BN_lshift1(arc, g_02146A68.unk00[id]);
    } else {
        u32 *tbl = (u32 *)g_02146A68.unk00;
        struct ArcRecord *rec = (struct ArcRecord *)tbl + id;
        u32 end = rec->end;
        u32 start = rec->start;

        FS_CreateFileFromMemory(arc, (void *)start, end - start);
    }
}







u32 func_02048E34(struct ArcHandle *arc, u32 member, u32 base, u32 size)
{
    u32 range[2];
    struct FatInfo info;
    u32 tmp = 0;
    u32 fatOffset;
    u32 off;

    FS_SeekFile(arc, 0xc, 0);
    FS_ReadFile(arc, &tmp, 2);
    fatOffset = tmp;

    FS_SeekFile(arc, fatOffset + 4, 0);
    FS_ReadFile(arc, &info, 6);
    if (info.count <= member) {
        func_02034734(func_02048DDC_File, 0xfb, func_02048DDC_Msg, info.count,
                      member);
    }

    off = fatOffset + info.offset;
    FS_SeekFile(arc, off + 4, 0);
    FS_ReadFile(arc, &tmp, 4);
    off += tmp;
    FS_SeekFile(arc, fatOffset + 0xc + member * 8, 0);

    FS_ReadFile(arc, range, 8);
    FS_SeekFile(arc, base + (off + 8 + range[0]), 0);

    if (size == 0) {
        size = range[1] - range[0];
    }
    return size;
}








/*
 * "Read one archive sub-file into a caller-supplied buffer", the defaulting
 * wrapper around func_02048D00.  func_02048D00 takes five arguments
 * (dst, archive id, member, mode, size_out); this entry point supplies zero
 * for the last two, which is why the body is a single `mov r3, #0` doing
 * double duty: the same zero reaches r3 (the fourth argument) and the one
 * word of outgoing stack area (the fifth).  The `push {r3, lr}` is the home
 * slot for that stack argument, not a saved register.
 *
 * func_02048D00 itself opens a temporary archive handle with func_02048DDC,
 * sizes the member with func_02048E34, reads it and closes the handle again.
 *
 * Kept in its own file so that the branch to func_02048D00 is witnessed from
 * outside this range by src/matched/func_02048F74.c, which calls the same
 * target (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F4C.c \
 *       --func func_02048F4C --addr 0x02048F4C --cc 1.1p1 --arm
 */
void func_02048F4C(void *dst, u32 archive_id, u32 member)
{
    func_02048D00(dst, archive_id, member, 0, 0);
}








/*
 * "Load one archive sub-file into a fresh heap block", the defaulting wrapper
 * around func_02048D54.  Same shape as func_02048F4C one entry above: the
 * callee takes (archive id, member, heap, mode, size_out) and this entry
 * point supplies zero for the last two, so one `mov r3, #0` feeds both r3 and
 * the single outgoing stack word, and `push {r3, lr}` is that word's home
 * slot rather than a saved register.
 *
 * This is the call the field code uses to pull a map matrix out of a/0/1/2's
 * sibling archive: func_02159B94 in ov010 calls it as
 * func_02048F60(9, matrix_id, heap), i.e. archive id 9 = a/0/0/9, with the
 * matrix id taken straight from the zone record's +0x04 lane.  See the
 * "Zone to map model" section of docs/ASSETS.md.
 *
 * Kept in its own file so the branch to func_02048D54 is witnessed from
 * outside this range by src/matched/func_02048F88.c
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F60.c \
 *       --func func_02048F60 --addr 0x02048F60 --cc 1.1p1 --arm
 */
void *func_02048F60(u32 archive_id, u32 member, u32 heap)
{
    return func_02048D54(archive_id, member, heap, 0, 0);
}








/*
 * The five-argument entry point of the same read: a pure forwarder to
 * func_02048D00 that copies the caller's one stack argument down into its own
 * outgoing stack area (`ldr ip, [sp, #8]` reads it across the two words this
 * function pushed) and leaves r0-r3 untouched.
 *
 * Kept in its own file so the branch to func_02048D00 is witnessed from
 * outside this range by src/matched/func_02048F4C.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F74.c \
 *       --func func_02048F74 --addr 0x02048F74 --cc 1.1p1 --arm
 */
void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode,
                   u32 *size_out)
{
    func_02048D00(dst, archive_id, member, mode, size_out);
}







/*
 * The five-argument entry point of the allocating load: a pure forwarder to
 * func_02048D54, with the caller's single stack argument copied down through
 * ip exactly as func_02048F74 does for func_02048D00.
 *
 * Kept in its own file so the branch to func_02048D54 is witnessed from
 * outside this range by src/matched/func_02048F60.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F88.c \
 *       --func func_02048F88 --addr 0x02048F88 --cc 1.1p1 --arm
 */
void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode,
                    u32 *size_out)
{
    return func_02048D54(archive_id, member, heap, mode, size_out);
}







/*
 * Promote-first callee of src/pending/func_02046E90.c (parks lane 2).
 * Open one member of an archive by path, size it, allocate the block from
 * the debug allocator, read the bytes in and close.  Same shape as its
 * sibling func_02049250 in the same cluster; the 0x4c frame is the 0x48
 * ArcFile handle at sp+4 plus the allocator's one outgoing stack word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F9C.c \
 *       --func func_02048F9C --addr 0x02048F9C --cc 1.1p1 --arm
 */
void *func_02048F9C(const char *path, u32 a, u32 heap)
{
    struct ArcFile file;
    void *p;
    u32 size;

    func_020788AC(&file);
    func_02078C18(&file, path);
    size = func_02048E34((struct ArcHandle *)(&file), a, 0, 0);
    p = func_02030734(heap, size, 0, func_02048F9C_File, 0x182);
    func_02078B70((struct FSFile *)(&file), p, size);
    func_02078A80(&file);
    return p;
}






u32 func_02049030(u32 a)
{
    char buf[0x48];
    int off;
    u16 hdr[3];

    off = 0;
    func_02048DDC((struct ArcFile *)buf, a);
    func_02078B44((struct FSFile *)buf, 0xc, 0);
    func_02078B70((struct FSFile *)buf, &off, 2);
    func_02078B44((struct FSFile *)buf, off + 4, 0);
    func_02078B70((struct FSFile *)buf, hdr, 6);
    func_02078A80(buf);
    return hdr[2];
}






u32 func_020490A8(u32 a, u32 b)
{
    char buf[0x48];
    u32 r;

    func_02048DDC((struct ArcFile *)buf, a);
    r = func_02048E34((struct ArcHandle *)buf, b, 0, 0);
    func_02078A80(buf);
    return r;
}





/*
 * Constructor: take a 0x50-byte record from the debug allocator, tie it to
 * the caller's object through func_02048DDC, run the one-time init at
 * func_0204919C and hand the record back.  The allocator's __FILE__/__LINE__
 * pair is the usual ABS32 into the packed string area plus a pooled 0x209,
 * which is not an ARM rotated immediate.
 */
void *sub_020490F4(u32 id, u32 heap)
{
    void *rec = func_02030734(heap, 0x50, 0, sub_020490F4_File, 0x209);

    func_02048DDC(rec, id);
    func_0204919C(rec);
    return rec;
}





/*
 * arc_tool.c's memory-file opener: carve a 0x50-byte FSFile with the
 * three-argument allocator (the heap id is this function's THIRD parameter
 * and reaches the allocator first), initialise it, bind it to the caller's
 * buffer and length, run the reader over it, and hand the FSFile back.
 *
 * The __FILE__ argument is the arc_tool.c anchor at 0x020A7EE0 that
 * src/matched/func_02048D54.c and the rest of the 0x02049xxx run already
 * pin; the stacked fifth argument is __LINE__ = 0x21f.  Its own pool word
 * (0x02049198) sits inside the compared range, so the site resolves through
 * the `string` class - the anchor's address is fixed by the terminator of the
 * string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204913C.c \
 *       --func func_0204913C --addr 0x0204913C --cc 1.1p1 --arm
 */
void *func_0204913C(void *a0, u32 a1, u32 heap)
{
    void *f = func_02030734(heap, 0x50, 0, func_0204913C_File, 0x21f);

    FS_InitFile(f);
    FS_CreateFileFromMemory(f, a0, a1);
    func_0204919C(f);
    return f;
}





/*
 * Walk the reader past its own header.  A halfword count at +0x4c is read
 * first, then skipped by, then a six-byte record is read into a stack buffer
 * whose first word is added to that count and whose third halfword lands in
 * the object at +0x4e; the running total then skips the following four-byte
 * field, which is read into the second half of the same buffer and added to
 * the total for the final offset at +0x48.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204919C.c \
 *       --func func_0204919C --addr 0x0204919C --cc 1.1p1 --arm
 */
void func_0204919C(u8 *p)
{
    u8 buf[12];
    u32 off;

    ((struct Obj05745 *)p)->f4C = 0;
    func_02078B44((struct FSFile *)p, 0xc, 0);
    func_02078B70((struct FSFile *)p, p + 0x4c, 2);
    func_02078B44((struct FSFile *)p, ((struct Obj05745 *)p)->f4C + 4, 0);
    func_02078B70((struct FSFile *)p, buf, 6);
    ((struct Obj05745 *)p)->f4E = ((struct Obj08859 *)buf)->f4;
    off = ((struct Obj05745 *)p)->f4C + ((struct Obj08859 *)buf)->f0;
    func_02078B44((struct FSFile *)p, off + 4, 0);
    func_02078B70((struct FSFile *)p, buf + 8, 4);
    ((struct Obj05745 *)p)->f48 = off + ((struct Obj08859 *)buf)->f8;
}





asm void func_02049238(void *arc)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_02078A80
    mov	r0, r4
    bl func_020307B0
    ldmfd sp!, {r4, pc}
}




/*
 * Read one member out of an open archive into a fresh heap block.  The
 * handle is an FSFile (0x48 bytes) with the archive's own bookkeeping
 * appended: the FAT offset at +0x4c and the member count at +0x4e, both
 * halfwords, and the image base at +0x48.
 *
 * The FAT entry is a pair of words (start, end) at
 * `fatOffset + 0xc + member * 8`, read into an on-stack two-word buffer;
 * the member's bytes then start at `imageBase + 8 + start` and run
 * `end - start` long.  The difference is written out twice, not cached in a
 * local: the original recomputes `sub r2, r3, r2` after the allocation from
 * two fresh stack loads.
 *
 * The assertion's variadic tail is two values, the count and the member,
 * not one.  The tell is that r3 is never written on the assert path: the
 * `ldrh r3, [r5, #0x4e]` that fed the guard's own `cmp` is still live, so
 * the first variadic argument costs no instruction at all, and only the
 * second reaches the stack.  Declared with a single variadic argument the
 * member lands in r3 instead and the `str r7, [sp]` disappears; see
 * docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md.
 *
 * 0x020A7EE0 is the arc_tool.c anchor this translation unit already uses in
 * func_02048D54; 0x020A7F18 is the assertion message, attested by the
 * terminator of the string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02049250.c \
 *       --func func_02049250 --addr 0x02049250 --cc 1.1p1 --arm
 */
void *func_02049250(struct ArcFile_02049250 *arc, u32 member, u32 heap)
{
    u32 range[2];
    void *buf;

    if (arc->count <= member) {
        func_02034734(func_02049250_File, 613, func_02049250_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    func_02078B44((struct FSFile *)arc, arc->imageBase + 8 + range[0], 0);

    buf = func_02030734(heap, range[1] - range[0], 0, func_02049250_File, 619);
    if (buf != 0) {
        func_02078B70((struct FSFile *)arc, buf, range[1] - range[0]);
    }
    return buf;
}




/*
 * Read one archive member straight into a caller-supplied buffer: the
 * allocating variant is func_02049250 one function above, and the FAT
 * lookup, the image-base offset and the length are identical.
 *
 * The bounds assertion is the same five-argument call func_02049250 uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204932C.c  *       --func func_0204932C --addr 0x0204932C --cc 1.1p1 --arm
 */
void func_0204932C(struct ArcFile_0204932C *arc, u32 member, void *dst)
{
    u32 range[2];

    if (arc->count <= member) {
        func_02034734(func_0204932C_File, 642, func_0204932C_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    func_02078B44((struct FSFile *)arc, arc->imageBase + 8 + range[0], 0);
    func_02078B70((struct FSFile *)arc, dst, range[1] - range[0]);
}




/*
 * Return the byte length of one archive member without reading it: the
 * FAT entry's two words are fetched and subtracted, and the file cursor is
 * left parked on the FAT rather than on the member's data.
 *
 * The bounds assertion is the same five-argument call func_02049250 uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020493D4.c  *       --func func_020493D4 --addr 0x020493D4 --cc 1.1p1 --arm
 */
u32 func_020493D4(struct ArcFile_020493D4 *arc, u32 member)
{
    u32 range[2];

    if (arc->count <= member) {
        func_02034734(func_020493D4_File, 665, func_020493D4_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, range, 8);
    return range[1] - range[0];
}




/*
 * Read a window out of the middle of one archive member.  Only the FAT
 * entry's first word is fetched (a 4-byte read, not 8), because the end
 * offset is never needed: the caller supplies both the offset into the
 * member and the length.
 *
 * The seek target is `offset + (imageBase + 8 + start)`: the accumulator of
 * the final `add` is the register holding the computed base, which is what
 * puts the caller's offset on the left of the source expression
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * The bounds assertion is the same five-argument call func_02049250 uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204944C.c  *       --func func_0204944C --addr 0x0204944C --cc 1.1p1 --arm
 */
void func_0204944C(struct ArcFile_0204944C *arc, u32 member, u32 offset, u32 size,
                   void *dst)
{
    u32 start;

    if (arc->count <= member) {
        func_02034734(func_0204944C_File, 689, func_0204944C_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, &start, 4);
    func_02078B44((struct FSFile *)arc, offset + (arc->imageBase + 8 + start), 0);
    func_02078B70((struct FSFile *)arc, dst, size);
}




/*
 * Store the absolute image offset of one archive member through an out
 * parameter.  Only the FAT entry's start word is read; the end word is
 * never touched, which is the 4-byte read rather than 8.
 *
 * The bounds assertion is the same five-argument call func_02049250
 * uses: the count is already in r3 from the guard's own `cmp`, so only
 * the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020494F4.c  *       --func func_020494F4 --addr 0x020494F4 --cc 1.1p1 --arm
 */
void func_020494F4(struct ArcFile_020494F4 *arc, u32 member, u32 *out)
{
    u32 start;

    if (arc->count <= member) {
        func_02034734(func_020494F4_File, 713, func_020494F4_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, &start, 4);
    *out = arc->imageBase + 8 + start;
}




/*
 * Return the absolute image offset of one archive member, the value
 * func_020494F4 writes through a pointer instead.
 *
 * The bounds assertion is the same five-argument call func_02049250
 * uses: the count is already in r3 from the guard's own `cmp`, so only
 * the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02049578.c  *       --func func_02049578 --addr 0x02049578 --cc 1.1p1 --arm
 */
u32 func_02049578(struct ArcFile_02049578 *arc, u32 member)
{
    u32 start;

    if (arc->count <= member) {
        func_02034734(func_02049578_File, 725, func_02049578_Msg,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, &start, 4);
    return arc->imageBase + 8 + start;
}




/*
 * Argument-swapping shim in front of the FS read: this entry point takes the
 * length before the destination, the reader takes them the other way round.
 * The swap costs the three-way `mov r3, r1 / mov r1, r2 / mov r2, r3`
 * shuffle and nothing else, so there is no frame at all and the call is a
 * tail call through a pool word and `bx ip`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020495F4.c \
 *       --func func_020495F4 --addr 0x020495F4 --cc 1.1p1 --arm
 */
void func_020495F4(struct ArcFile_020495F4 *arc, u32 size, void *dst)
{
    func_02078B70((struct FSFile *)arc, dst, size);
}



asm void NHTTPi_GetConnection(void)
{
    ldr ip, =func_02078B44
    mov r2, #0
    bx ip
}




u16 func_0204961C(void *obj)
{
    return ((struct Obj17354 *)obj)->f4E;
}




u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6)
{
    u32 ret = func_0204A1BC((int)a0, (int)a1, a5, a6);
    return func_0204968C((void *)ret, (u32)a2, (u32)a3, a4, a5);
}




/*
 * Seven-argument entry point of the text-printing layer: resolve a handle
 * through sub_0204A380 from the first two arguments and the last two, then
 * hand that handle plus the middle arguments to sub_0204968C.
 *
 * The sixth argument is read from the caller's stack slot twice, once as
 * sub_0204A380's third argument and once as sub_0204968C's fifth: the
 * compiler will not keep it in a callee-saved register across the first
 * call, because re-reading the incoming slot is free
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The seventh is read with `ldrh`, which is what names it u16.  The third
 * and fourth arguments are parked in r5/r4 because they are live across
 * the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02049658.c \
 *       --func sub_02049658 --addr 0x02049658 --cc 1.1p1 --arm
 */
u32 sub_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    return sub_0204968C((void *)((u32)sub_0204A380(a, b, f, g)), c, d, e, f);
}




/*
 * The write-into-an-existing-slot counterpart of src/matched/sub_0204979C.c:
 * the same func_02062A4C lookup and the same "size of zero means the object's
 * own size at +0x10" rule, but the result goes straight into func_02040B1C
 * instead of coming back as a packed handle, and the caller's handle is
 * released either way. The whole body sits inside the `if`, which is why the
 * failed lookup is a forward branch to the release rather than a shared exit
 * block.
 *
 * `and r0, r6, #0xff` is func_02040B1C's first parameter being `u8`, not a
 * mask written in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204968C.c \
 *       --func sub_0204968C --addr 0x0204968C --cc 1.1p1 --arm
 */
u32 sub_0204968C(void *buf, u32 a1, u32 a2, u32 a3, u32 unused)
{
    struct Res *res;

    if (func_02062A4C(buf, (void **)(&res)) != 0) {
        if (a3 == 0) {
            a3 = res->unk_10;
        }
        func_02040B1C((u8)a1, (const void *)res->unk_14, a3, a2);
    }

    ENV_SetResourceSet(buf);
    return a3;
}




/*
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to func_0204979C to be registered, and
 * releases the loader's handle again. Returning 0 on a failed load is the
 * `movs`/`moveq`/`popeq` triple: the load result is tested by the move that
 * stores it, so no separate `cmp` appears.
 *
 * The flag word is the sixth argument and arrives as a halfword, and
 * func_0204A1BC's fourth parameter is `u16`, which is what turns
 * `(flags & 0x7FFF) | 0x8000` into an `and`/`orr` pair followed by a
 * `lsl #16`/`lsr #16` truncation rather than a single `orr`.
 *
 * The twin of src/matched/sub_02049740.c, differing only in which loader it
 * calls. func_0204A1BC has thirteen further callers image-wide and
 * func_0204979C its second caller at 0x02049780, so both resolve through the
 * `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020496E4.c \
 *       --func sub_020496E4 --addr 0x020496E4 --cc 1.1p1 --arm
 */
u32 sub_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags)
{
    void *buf;
    u32 res;

    buf = (void *)func_0204A1BC((u32)a0, (u32)a1, (u32)a4, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = func_0204979C(buf, a2, a3);
    ENV_SetResourceSet(buf);
    return res;
}




/*
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to func_0204979C to be registered, and
 * releases the loader's handle again. Returning 0 on a failed load is the
 * `movs`/`moveq`/`popeq` triple: the load result is tested by the move that
 * stores it, so no separate `cmp` appears.
 *
 * The flag word is the sixth argument and arrives as a halfword, and
 * func_0204A380's fourth parameter is `u16`, which is what turns
 * `(flags & 0x7FFF) | 0x8000` into an `and`/`orr` pair followed by a
 * `lsl #16`/`lsr #16` truncation rather than a single `orr`.
 *
 * func_0204A380 resolves through the `matched` class against
 * src/matched/func_0204A380.c; func_0204979C through the `label` class, its
 * outside witness being the second caller at 0x02049724.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02049740.c \
 *       --func sub_02049740 --addr 0x02049740 --cc 1.1p1 --arm
 */
u32 sub_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags)
{
    void *buf;
    u32 res;

    buf = func_0204A380(a0, a1, a4, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = func_0204979C(buf, a2, a3);
    ENV_SetResourceSet(buf);
    return res;
}




/*
 * Registers a loaded graphics buffer and answers a packed handle: the slot
 * index in the low halfword and the size the caller asked for (or the
 * object's own size at +0x10, when the caller passed zero) in the high one.
 * A failed lookup and a -1 from the allocator both return a plain 0.
 *
 * The two failure paths share one `mov r0, #0` / `pop` block at 0x020497F8.
 * Statements sit between the two guards, so only an explicit `goto` to a
 * trailing `return 0` reproduces that; written as two plain `return 0`
 * statements mwcc predicates both epilogues instead and 53 of 100 bytes move
 * (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *
 * The packed result is written `((u16)a2 << 16) | (u16)slot`, not the other
 * way round: the accumulator of a commutative chain is its second operand
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md),
 * and only this order leaves the low half in r0 and folds the high half in as
 * `orr r0, r0, r1, lsl #16`.
 *
 * func_02062A4C fills a caller-owned pointer through its second argument, so
 * the local is read back twice, once inside the `a2 == 0` arm and once for
 * the unconditional `+0x14` field. That is why the pair of `ldr` from `[sp]`
 * straddles the predicated `ldreq`: the conditional read cannot be shared
 * with the unconditional one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204979C.c \
 *       --func sub_0204979C --addr 0x0204979C --cc 1.1p1 --arm
 */
u32 sub_0204979C(void *buf, u32 a1, u32 a2)
{
    struct Res *res;
    s32 slot;

    if (func_02062A4C(buf, (void **)(&res)) == 0) {
        goto fail;
    }

    if (a2 == 0) {
        a2 = res->unk_10;
    }

    slot = func_02040B58(a1, (const void *)res->unk_14, a2);
    if (slot == -1) {
        goto fail;
    }

    return ((u16)a2 << 16) | (u16)slot;

fail:
    return 0;
}




/*
 * Byte-correct, capped at MATCH. Blocked on: func_0204982C (0x0204982C) has
 * exactly one branch reference in the whole image, the `bl` at 0x02049824
 * inside this function, and it begins at the first byte past this function's
 * own extent (02049800..0204982C), so no evidence class witnesses it. This
 * used to print EXACT anyway (`compare()` claimed EXACT from literal byte
 * equality alone, without checking that every relocation field had actually
 * been resolved), because the PC24 field's compiler-emitted displacement to
 * the immediately-following address happens to coincide with the image's
 * bytes by plain adjacency, not by attestation; `compare()` now requires
 * `fb.mask` to be entirely hard before claiming EXACT, so this correctly
 * reports MATCH. It graduates for real only once 0x0204982C has an EXACT
 * entry of its own: src/pending/sub_0204982C.c is the C for it, stuck at
 * MATCH on the unattestable data address 0x020A135C. func_0204A380 resolves
 * normally (label, and src/matched/func_0204A380.c).
 *
 * A seven-argument front end that loads an archive member and hands the
 * buffer to the flush-and-dispatch worker; the flag word is passed straight
 * through as a halfword rather than having its top bit forced on, which is
 * what distinguishes this family member from src/matched/sub_02049740.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02049800.c \
 *       --func sub_02049800 --addr 0x02049800 --cc 1.1p1 --arm
 */
u32 sub_02049800(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    return func_0204982C(func_0204A380(a0, a1, a5, a6), a2, a3, a4);
}



extern void (*g_020A135C[])(u32 addr, u32 a1, u32 size);




/*
 * Byte-correct, capped at MATCH. Blocked on: g_020A135C (0x020A135C) is named
 * by exactly one word in the whole image, the pool word at 0x02049898 inside
 * this function, so the `literal` class has no witness outside the compared
 * range, and being plain data it has no other class available. The range is a
 * single function, so there is no cut to make. It needs a second reference
 * somewhere in the image, which does not exist, or an attested data
 * definition at 0x020A135C. The other three relocations resolve.
 *
 * This is the DMA-flush variant of src/matched/sub_0204968C.c: the same
 * func_02062A00 lookup (the sibling of func_02062A4C), the same "a size of
 * zero means the object's own size at +0x10" rule, then a `DC_FlushRange`
 * over the object's buffer and a dispatch through the five-entry function
 * table at 0x020A135C indexed by the second argument.
 *
 * The buffer pointer is read from the caller-owned local twice, once for the
 * flush and once for the dispatch, because the call between them may write
 * through the pointer the local holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204982C.c \
 *       --func sub_0204982C --addr 0x0204982C --cc 1.1p1 --arm
 */
u32 sub_0204982C(void *buf, u32 kind, u32 a2, u32 size)
{
    struct Res *res;

    if (func_02062A00(buf, (void **)(&res)) != 0) {
        if (size == 0) {
            size = res->unk_10;
        }
        DC_FlushRange(res->unk_14, size);
        g_020A135C[kind](res->unk_14, a2, size);
    }

    ENV_SetResourceSet(buf);
    return size;
}



/*
 * Seven-argument front end: load an archive member with the top allocation
 * bit forced on, exactly as src/matched/sub_020496E4.c does, and forward the
 * buffer to func_02049A18 with two of its six arguments pinned to zero. The
 * handle is not released here; func_02049A18 does that itself (see its
 * near-miss note in docs/notes/func_02049A18.c.txt, which is where its
 * six-argument shape comes from).
 *
 * The two zeros are one `mov r3, #0` reused for the register argument and
 * the stack argument, so the stack store of a4 has to be emitted between the
 * two: writing the zeros first costs a second materialisation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204989C.c \
 *       --func sub_0204989C --addr 0x0204989C --cc 1.1p1 --arm
 */
void sub_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags)
{
    func_02049A18((void *)func_0204A1BC((u32)a0, (u32)a1, (u32)a5, (u16)((flags & 0x7FFF) | 0x8000)),
                  a2, a3, 0, a4, 0);
}



/*
 * The same two-step shape as sub_02049658, but the handle lookup forces
 * the top bit of its u16 selector on: `(g & 0x7fff) | 0x8000`.  0x7fff
 * does not fit an ARM rotated immediate, so it costs a pool word, while
 * 0x8000 is `orr r2, r2, #0x8000` in one instruction; the `lsl #16` /
 * `lsr #16` pair after them is the u16 truncation of the result, not a
 * bitfield (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * read the other way: an equal-amount pair is the narrowing cast).
 *
 * The second call gets two spliced zeros, one in r3 and one in the second
 * outgoing stack slot; a single `mov r3, #0` serves both, which is why it
 * lands between the two stack stores rather than before them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020498F4.c \
 *       --func sub_020498F4 --addr 0x020498F4 --cc 1.1p1 --arm
 */
void sub_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    sub_02049A18(sub_0204A380(a, b, f, (u16)((g & 0x7fff) | 0x8000)),
                 c, d, 0, e, 0);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Sound / audio event trigger wrappers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204994C.c \
 *       --addr 0x0204994C --arm
 */
u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = func_0204A1BC(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 0);
}



u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)func_0204A380(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 0);
}



u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)func_0204A380(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 1);
}



/*
 * arc_tool.c (wave 13): the palette-upload worker the sound/palette front
 * ends of unit_0204994C.c, sub_0204989C.c and sub_020498F4.c forward to.
 * Look up the resource's palette block; default the size to the block's own
 * (+0x08); when `add` is non-zero, add it to every entry of the data at +0x0C
 * -- as halfwords (size / 2 of them) when func_0204169C says the channel is
 * not 8-bit, else as bytes; then upload through func_02040AF0 plus the
 * flag-selected commit (func_02041B6C / func_020409B4) or func_020409E0, and
 * release the resource either way.  Every `and rN, r7, #0xff` is a callee's
 * u8 channel parameter, not a cast in the source.
 *
 * WHAT CLOSED IT (docs/notes/func_02049A18.c.txt: 300 against 296, 122 out):
 * the callees take `u8 channel` and the caller passes the u32 unchanged; the
 * two loops each own a block-scoped counter (a shared `i` makes the compiler
 * hoist one `mov r3, #0` above the arm test, 4 bytes short); and inside each
 * block the counter is declared BEFORE the element pointer (the other order
 * swaps the two registers in both loops, 17 bytes).
 */
u32 func_02049A18(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag)
{
    struct Pal *pal;

    if (func_02062B30(file, (void **)(&pal)) != 0) {
        if (size == 0)
            size = pal->size;
        if (add != 0) {
            if (func_0204169C((u8)channel) == 0) {
                u32 i;
                u16 *p = (u16 *)pal->data;
                for (i = 0; i < size / 2; i++)
                    p[i] += (u16)add;
            } else {
                u32 i;
                u8 *p = pal->data;
                for (i = 0; i < size; i++)
                    p[i] += (u8)add;
            }
        }
        if ((int)func_0204162C((u8)channel) != 0) {
            func_02040AF0((u8)channel, pal->data, size, a2);
            if (flag != 0)
                func_02041B6C(channel);
            else
                func_020409B4(channel);
        } else {
            func_020409E0((u8)channel, pal->data, size, a2);
        }
    }
    return func_020307B0(file);
}



/*
 * A whole translation unit range, matched as one byte range.
 *
 * Two sibling entry points of the text-printing layer, each a six-to-seven
 * argument forwarder that splices a zero in as the fourth argument of the
 * real worker (sub_02049B90 and sub_02049BDC respectively).
 *
 * The shape is the whole content: `stmdb sp!, {lr}` plus `sub sp, #0xc`
 * builds the outgoing stack argument area, the two incoming stack
 * arguments are lifted out at [sp,#0x10] and [sp,#0x14], and `stm sp,
 * {r3, lr}` writes the displaced r3 and the first lifted argument into
 * the callee's slots in one go.  Only then is r3 reloaded with the
 * spliced 0.  The last argument is read with `ldrh`, which is the only
 * evidence that it is a u16 rather than a word.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02049B40.c \
 *       --addr 0x02049B40 --arm
 */
void sub_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    sub_02049B90(a, b, c, 0, d, e, f);
}



void sub_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    sub_02049BDC(a, b, c, 0, d, e, f);
}



/*
 * One of two seven-argument entry points on the cell-actor system, an
 * address apart, that differ only in which half of func_02049C28's dispatch
 * they reach first (func_0204A380 in func_02049BDC, 0x0204A1BC here); both
 * then forward into 0x02049C28 itself.
 *
 * The seventh parameter is a u16: it is read off the caller's stack with
 * `ldrh` (a 32-bit parameter would be `ldr`), masked with the pooled 0x7FFF
 * and re-set to the 0x8000 bit before being passed as the fourth argument of
 * the dispatch call.  0x7FFF is not an ARM immediate, which is why it costs a
 * pool word rather than a `mov`.
 *
 * The second call's first argument is the first call's result: no register is
 * written for it, r0 is simply left as the callee returned it.  Declaring the
 * dispatch call's own first argument as a saved parameter instead costs the
 * function a callee-saved register, a 4-byte frame and 16 bytes.
 *
 * Complements func_02049BDC, which is a separate file on purpose: 0x02049C28
 * has five branch references image wide and three of them are inside
 * 0x02049C28 itself, so a `tu` spanning both wrappers loses every witness and
 * only the two single-function ranges keep one each.
 */
void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = func_0204A1BC(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    func_02049C28((void *)r, a2, a3, a4, a5);
}



/*
 * The second half of the pair described in src/matched/func_02049B90.c: same
 * seven-argument shape, reaching func_0204A380 rather than func_0204A1BC
 * before forwarding into 0x02049C28.
 *
 * Kept as its own file deliberately.  Both halves call 0x02049C28, and
 * 0x02049C28 has five branch references image wide with three of them inside
 * 0x02049C28 itself, so a `tu` span over both wrappers has no witness left
 * for either call and caps at MATCH; as two single-function ranges each is the
 * other's witness and both are EXACT.
 */
void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = (u32)func_0204A380(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    func_02049C28((void *)r, a2, a3, a4, a5);
}



/*
 * arc_tool.c (wave 13): load a palette resource into VRAM.  With a loaded
 * resource file: look up its PMCP block (optional) and its PLTT block; when
 * the PLTT block is there, advance its data pointer by `offset`, and when the
 * caller passed size 0 take the block's own size (no PMCP) or the PMCP count
 * times 0x20 (format 3) / 0x200 (anything else), less `offset`; flush the
 * range and dispatch through the eight-entry loader table 0x020A1364 by
 * `kind`, wrapping kinds 2/6/3/7 (source order, which is what the emitted
 * bodies say) in the matching Begin/End extended-palette calls.  The file is
 * released either way.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02049C28.c.txt: 20 bytes out, "a4 in r5 at
 * entry, v separately"):
 *   - there is no separate `v`: the size PARAMETER is the value that is
 *     defaulted, reduced by offset and passed on (`size = ...; size -=
 *     offset;`), which is why the image loads it into r5 at entry and keeps
 *     it there;
 *   - the early `if (file == 0) return;` the note's shape omitted (the
 *     image's `movs sb, r0` / `addeq` / `popeq`);
 *   - the two out-pointer locals declared PLTT first, PMCP second, so PMCP
 *     lands at sp+0 and PLTT at sp+4.
 * The table's const qualifier does not change the bytes.
 */
void func_02049C28(void *file, u32 kind, u32 offset, u32 dest, u32 size)
{
    struct Pltt *pltt;
    u16 *pmcp;
    int cmp;

    if (file == 0)
        return;
    cmp = func_02062AD4(file, (void **)(&pmcp));
    if (func_02062A98(file, (void **)(&pltt)) != 0) {
        pltt->data += offset;
        if (size == 0) {
            if (cmp == 0)
                size = pltt->size;
            else
                size = *pmcp * (pltt->fmt == 3 ? 0x20 : 0x200);
            size -= offset;
        }
        func_020862F0(pltt->data, size);
        switch (kind) {
        case 2:
            func_0207F308();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F428();
            break;
        case 6:
            func_0207F5B0();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F65C();
            break;
        case 3:
            func_0207F47C();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F560();
            break;
        case 7:
            func_0207F6A8();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F754();
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        default:
            g_020A1364[kind](pltt->data, dest, size);
            break;
        }
    }
    func_020307B0(file);
}



/*
 * Cell-actor binding helpers.  Each binds an actor of a given kind through
 * func_0204A1BC (kind table 1, 5-argument form) or func_0204A380 (kind
 * table 2, wrapper over func_0204A39C), runs the per-kind hook, and releases
 * the actor again when the hook fails.  func_02049F34 / func_02049F78 are
 * the 4-argument forms and pass 0 as the third argument.
 */
void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A4C(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A4C(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A00(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A00(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062B30(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049EF4(void *a0, u32 a1, u32 a2, void **out, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062B30(res, out)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3)
{
    void *res = (void *)func_0204A1BC(a0, a1, 0, a3);
    if (res != 0) {
        if (!func_02062A98(res, (void **)a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3)
{
    void *res = func_0204A380(a0, a1, 0, a3);
    if (res != 0) {
        if (!func_02062A98(res, (void **)a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049FBC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062820((int)res, (int *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_02049FFC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062820((int)res, (int *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_0204A03C(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062670(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



/*
 * A whole translation unit, matched as one byte range.
 */
void *func_0204A07C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062670(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_0204A0BC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062920((u32)res, (u32 *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_0204A0FC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062920((u32)res, (u32 *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_0204A13C(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_0206267C(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



void *func_0204A17C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_0206267C(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}



/*
 * arc_util.c's "open a member and read it" entry.  The three __LINE__
 * constants 1599, 1603 and 1611 are the only three the pool carries, and
 * each is the fifth argument of a func_02030734 call whose fourth
 * argument is the file-name word at 0x020A7F30 ("arc_util.c").
 */
int func_0204A1BC(int a0, int a1, int a2, int a3)
{
    int t;
    int r;
    int t2;

    if (a2 != 0) {
        t = func_020490A8(a0, a1);
        r = (int)func_02030734((u16)((a3 & 0x7fff) | 0x8000), t, 0, sArcUtil3730, 1599);
    } else {
        t = func_020490A8(a0, a1);
        r = (int)func_02030734(a3, t, 0, sArcUtil3730, 1603);
    }
    func_02048F4C((void *)r, a0, a1);
    if (a2 != 0) {
        t2 = (int)func_02030734(a3, ((struct Obj16074 *)r)->f0 >> 8, 0, sArcUtil3730, 1611);
        func_020834C0(r, t2);
        func_020307B0((void *)r);
        r = t2;
    }
    return r;
}



/*
 * The out-parameter twin of func_0204A1BC directly above it: the handle
 * func_020490A8 returns is written through the fifth (stack) argument and
 * the same three arc_util.c line numbers appear, shifted by 43.
 */
int func_0204A298(int a0, int a1, int a2, int a3, u32 *out)
{
    int r;
    int t;

    *out = func_020490A8(a0, a1);
    if (a2 != 0) {
        r = (int)func_02030734((u16)((a3 & 0x7fff) | 0x8000), *out, 0, sArcUtil3730, 1642);
    } else {
        r = (int)func_02030734(a3, *out, 0, sArcUtil3730, 1646);
    }
    func_02048F4C((void *)r, a0, a1);
    if (a2 != 0) {
        *out = ((struct Obj16075 *)r)->f0 >> 8;
        t = (int)func_02030734(a3, *out, 0, sArcUtil3730, 1656);
        func_020834C0(r, t);
        func_020307B0((void *)r);
        r = t;
    }
    return r;
}



void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3)
{
    u32 unk;
    return func_0204A39C(a0, a1, a2, a3, &unk);
}



/*
 * arc_util.c: load one archive member into a fresh heap block, optionally
 * LZ8-decompressing it into a second block.  ARM, not Thumb (the old
 * pending file compiled Thumb and read ISA).
 *
 * Shape facts the image fixes: the allocation is written in both arms of
 * the decompress test (the image cross-jumps them onto one call, with
 * *out_size re-read at the join); the heap id is a u32 narrowed at each
 * use; the NULL check wraps the rest rather than returning early, so every
 * exit shares `mov r0, r4; pop`; on a failed second allocation the result
 * is the NULL block (buf = d unconditionally).  The decompressing arm is
 * line 1709 and the plain arm 1713: the pool order says so.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204A39C.c  *       --func func_0204A39C --addr 0x0204A39C --arm --cc 1.1p1
 */
void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size)
{
    void *buf;
    void *d;

    *out_size = func_020493D4(narc, fileId);
    if (decompress != 0) {
        buf = func_02030734((u16)(((u16)heapId & 0x7FFF) | 0x8000), *out_size, 0, lbl_020A7F30, 1709);
    } else {
        buf = func_02030734((u16)heapId, *out_size, 0, lbl_020A7F30, 1713);
    }
    if (buf != 0) {
        func_0204932C(narc, fileId, buf);
        if (decompress != 0) {
            *out_size = ((struct Obj16076 *)buf)->f0 >> 8;
            d = func_02030734((u16)heapId, *out_size, 0, lbl_020A7F30, 1725);
            if (d != 0) {
                MI_UncompressLZ8(buf, d);
                func_020307B0(buf);
            }
            buf = d;
        }
    }
    return buf;
}
