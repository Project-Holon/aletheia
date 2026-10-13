/*
 * file:     no_gear.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFEC4, func_021EFECC, func_021EFF54, func_021F0058, func_021F007C, func_021F00C4, func_021F00C8, func_021F00F8
 * address:  0x021EFEC0
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02043598  0x02043598  arm
 *   d_021F0134     0x021F0134  data  ov030  a4
 *   d_021F0140     0x021F0140  data  ov030  a4
 *   func_02040588  0x02040588  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021F014C     0x021F014C  data  ov030  a4
 *   d_021F016C     0x021F016C  data  ov030  a4
 *   d_021F018C     0x021F018C  data  ov030  a4
 *   func_0203FB44  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02030734  0x02030734  arm
 *   str_021F01C0   0x021F01C0  data   ov030  a1
 *   func_0201283C 0x0201283C thumb
 *   func_0201058C 0x0201058C thumb
 */
#include "../ov021/field_subscreen_types.h"

struct GameSystem;
struct GameData;
struct PlayerStatus;
struct ArchiveHandle;

/* Background setup record handed to the BG system (one per screen layer). */
struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    u8  screenSize;
    u8  colorMode;
    u8  screenBase;
    u8  charBase;
    u32 extPaletteSlot;
    u8  priority;
    u8  areaOver;
    u8  dummy;
    u8  mosaicFlag;
    u32 mosaic;
};

/* Panel shown on the lower screen when the save has no C-Gear (0x20 bytes). */
typedef struct NoGearWork {
    void (*stepFunc)(struct NoGearWork *work);
    u32 pad04;
    u16 heapId;
    u16 pad0A;
    u32 pad0C[2];
    u32 charBlock;                  /* BG char area: low 16 bits offset, high 16 bits size */
    struct GameSystem *gameSystem;
    u32 pad1C;
} NoGearWork;

extern struct ArchiveHandle *func_020490F4(u32 archiveId, u32 heapId);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct PlayerStatus *func_02012944(struct GameData *gameData);
extern u8 func_02008550(const struct PlayerStatus *player);
extern void func_02049B68(struct ArchiveHandle *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u16 heapId);
extern u32 func_02049740(struct ArchiveHandle *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u16 heapId);
extern u32 func_02049990(struct ArchiveHandle *archive, u32 fileId, u32 bgId, u32 x, u32 y, u32 width, u32 height, u16 heapId);
extern void func_02049238(struct ArchiveHandle *archive);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02043598(u32 planeMask, u32 enable);
extern void func_02040588(unsigned char bgId, unsigned char visible);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *template, u32 type);
extern void func_0204047C(int bgId, unsigned short priority);
extern void func_02041300(u32 bgId, int a1, int a2, int a3, u8 width, u8 height, u8 mode);
extern void func_020409B4(u32 bgId);
extern void func_0203FB44(u32 bgId, u32 offset, u32 size);
extern void func_020403F4(u32 bgId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0201283C(struct GameData *gameData);
extern u32 func_0201058C(void *key);
void func_021EFEC0(void (**slot)(NoGearWork *), void (*stepFunc)(NoGearWork *));
void func_021EFEC4(NoGearWork *work, void (*stepFunc)(NoGearWork *), int line);
void func_021EFECC(NoGearWork *work);
void func_021EFF54(void);
void func_021F0058(NoGearWork *work);
void func_021F007C(NoGearWork *work);
void func_021F00C4(NoGearWork *work);
NoGearWork *func_021F00C8(void *cgearSave, FieldSubscreen *subscreen, struct GameSystem *gameSystem);
void func_021F00F8(NoGearWork *work);
void func_021F0114(void);
extern const u32 d_021F0134[];
extern const u32 d_021F0140[];
extern struct BgTemplate d_021F014C;
extern struct BgTemplate d_021F016C;
extern struct BgTemplate d_021F018C;
extern char str_021F01C0[];


void func_021EFEC0(void (**slot)(NoGearWork *), void (*stepFunc)(NoGearWork *))
{
    *slot = stepFunc;
}



/*
 * Tail call to the unlabelled ov030 leaf func_021EFEC0; its ABS32 pool word
 * is now witnessed by the EXACT shard entry for func_021EFEC0 (matched x1).
 */
void func_021EFEC4(NoGearWork *work, void (*stepFunc)(NoGearWork *), int line)
{
    func_021EFEC0(&work->stepFunc, stepFunc);
}



void func_021EFECC(NoGearWork *work)
{
    struct ArchiveHandle *archive;
    int variant;

    archive = func_020490F4(0x1E, work->heapId);
    variant = func_02008550(func_02012944(func_020120F4(work->gameSystem)));
    func_02049B68(archive, d_021F0134[variant], 4, 0, 0, work->heapId);
    work->charBlock = func_02049740(archive, d_021F0140[variant], 6, 0, 0, work->heapId);
    func_02049990(archive, 3, 6, 0, (u16)work->charBlock, 0, 0, work->heapId);
    func_02049238(archive);
    func_0203D34C(0, work->heapId);
    func_02043598(0x10, 1);
}



void func_021EFF54(void)
{
    int bgId;

    for (bgId = 4; bgId <= 7; bgId++) {
        func_02040588((u8)bgId, 0);
    }
    {
        struct BgTemplate template = d_021F014C;
        func_0203FCA0(6, &template, 0);
        func_02040588((u8)6, 1);
        func_0204047C(6, 3);
        func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(6);
    }
    {
        struct BgTemplate template = d_021F016C;
        func_0203FCA0(5, &template, 0);
        func_02040588((u8)5, 1);
        func_0204047C(5, 1);
        func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(5);
    }
    {
        struct BgTemplate template = d_021F018C;
        func_0203FCA0(4, &template, 0);
        func_02040588((u8)4, 1);
        func_0204047C(4, 2);
        func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(4);
    }
}


void func_021F0058(NoGearWork *work)
{
    func_021EFF54();
    func_021EFECC(work);
    func_021EFEC4(work, func_021F00C4, 0x149);
}



/*
 * (followed by an unlabelled 2-byte `bx lr` stub at 0x021F00C4)
 */
void func_021F007C(NoGearWork *work)
{
    u32 charBlock = work->charBlock;

    func_0203FB44(6, (u16)charBlock, (u16)(charBlock >> 16));
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02043598(0x10, 0);
}


/*
 * extent: empty callback bx lr, two-byte alignment then separate constructor
 * starts 0x021F00C8; callback alone is reproduced.
 * interface: func_021F0058 installs this callback and func_021F00F8 invokes
 * it with its object pointer in r0. Empty body does not read that context.
 */
void func_021F00C4(NoGearWork *work)
{
}



NoGearWork *func_021F00C8(void *cgearSave, FieldSubscreen *subscreen, struct GameSystem *gameSystem)
{
    NoGearWork *work;

    work = func_02030734(0x15, 0x20, 1, str_021F01C0, 0x17A);
    work->heapId = 0x15;
    work->gameSystem = gameSystem;
    func_021F0058(work);
    return work;
}


/*
 * extent: empty follower func_021F0114 then two-byte zero padding.
 */
void func_021F00F8(NoGearWork *work)
{
    if (work->stepFunc != 0) {
        work->stepFunc(work);
    }
    func_0201058C(func_0201283C(func_020120F4(work->gameSystem)));
}


void func_021F0114(void)
{
}
