/*
 * function: MBi_SetSegmentInfo
 * address:  0x021F3830
 * packet:   pkt_ov107_021F3830
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_SetSegmentInfo (TwlSDK/libmb.TWL.HYB.a(mb_fileinfo.o)).
 *           Transcribed from the vendor source, which this tree ships:
 *           sdk/TwlSDK/build/libraries/mb/common/src/mb_fileinfo.c:725.
 *           The three locals of the ARM7STATIC arm are declared
 *           `int reload_flag; int error_flag; u32 load_last_addr;` and
 *           initialised by one chained statement `reload_flag = error_flag = 0;`
 *           -- separate initialisers (or the reverse declaration order) put the
 *           zero in r4/r2 the other way round and cost 3 bytes at +0x0080.
 *
 * symbols:
 *   func_02088234  0x02088234  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 offset;
    u32 entry;
    u32 ram_address;
    u32 size;
} RomRegion;

typedef struct {
    u8 pad0[0x20];
    RomRegion main;
    RomRegion sub;
} RomHeader;

typedef struct {
    u32 recv_addr;
    u32 load_addr;
    u32 size;
    u32 target : 1;
} SegInfo;

enum SegType { SEG_A, SEG_B, SEG_C };

extern void func_02088234(void);


void MBi_SetSegmentInfo(const RomHeader *hdr, enum SegType *list, SegInfo *seg, u32 *child_recv)
{
    const RomRegion *romRegp;

    switch (*list) {
    case SEG_A:
        romRegp = &hdr->main;
        if (romRegp->ram_address >= 0x2000000 && romRegp->ram_address < 0x22C0000
            && (romRegp->ram_address + romRegp->size) <= 0x22C0000) {
            seg->size = romRegp->size;
            seg->load_addr = romRegp->ram_address;
            seg->recv_addr = seg->load_addr;
            seg->target = 0;
        } else {
            func_02088234();
        }
        break;
    case SEG_B: {
        int reload_flag;
        int error_flag;
        u32 load_last_addr;

        reload_flag = error_flag = 0;
        romRegp = &hdr->sub;
        load_last_addr = romRegp->ram_address + romRegp->size;
        if (romRegp->ram_address >= 0x2000000 && romRegp->ram_address < 0x23FE800) {
            if (load_last_addr <= 0x2300000) {
            } else if (load_last_addr < 0x23FE800 && romRegp->size <= 0x40000) {
                reload_flag = 1;
            } else {
                error_flag = 1;
            }
        } else if (romRegp->ram_address >= 0x3040000 && romRegp->ram_address < 0x3057000) {
            if (load_last_addr <= 0x3057000)
                reload_flag = 1;
            else
                error_flag = 1;
        } else {
            error_flag = 1;
        }
        if (error_flag == 1)
            func_02088234();
        seg->size = romRegp->size;
        seg->load_addr = romRegp->ram_address;
        if (!reload_flag) {
            seg->recv_addr = seg->load_addr;
        } else {
            seg->recv_addr = *child_recv;
            *child_recv += seg->size;
        }
        seg->target = 1;
        break;
    }
    case SEG_C:
        seg->size = 0x160;
        seg->load_addr = 0x27FFE00;
        seg->recv_addr = seg->load_addr;
        seg->target = 0;
        break;
    }
}
