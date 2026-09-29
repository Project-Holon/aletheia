/*
 * function: func_021F3830
 * address:  0x021F3830
 * packet:   pkt_ov107_021F3830
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes: DIFF, 115 bytes. const RomHeader/RomRegion params give the right load CSE. Residue: case B has error_flag in r3 and load_last_addr in r2 (image: error r2, last r3); the inner size<=0x40000 test tail-merges with the next arm's movls/movhi pair (image keeps it as movls r4 / bls / b error). Tried decl permutations, flag init orders, || chain, inverted inner test.
 *
 * sdk:      MBi_SetSegmentInfo (libmb.TWL.HYB.a mb_fileinfo.o)
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

void func_021F3830(const RomHeader *hdr, enum SegType *list, SegInfo *seg, u32 *child_recv)
{
    u32 load_last_addr;
    int reload_flag;
    int error_flag;
    const RomRegion *romRegp;

    switch (*list) {
    case SEG_A:
        romRegp = &hdr->main;
        if (romRegp->ram_address >= 0x2000000 && romRegp->ram_address < 0x22C0000 &&
            romRegp->ram_address + romRegp->size <= 0x22C0000) {
            seg->size = romRegp->size;
            seg->load_addr = romRegp->ram_address;
            seg->recv_addr = romRegp->ram_address;
            seg->target = 0;
        } else {
            func_02088234();
        }
        break;
    case SEG_B:
        romRegp = &hdr->sub;
        reload_flag = error_flag = 0;
        load_last_addr = romRegp->ram_address + romRegp->size;
        if (romRegp->ram_address >= 0x2000000 && romRegp->ram_address < 0x23FE800) {
            if (load_last_addr <= 0x2300000) {
            } else if (load_last_addr < 0x23FE800) {
                if (romRegp->size <= 0x40000)
                    reload_flag = 1;
                else
                    error_flag = 1;
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
        seg->load_addr = romRegp->ram_address;
        seg->size = romRegp->size;
        if (reload_flag == 0) {
            seg->recv_addr = romRegp->ram_address;
        } else {
            seg->recv_addr = *child_recv;
            *child_recv += romRegp->size;
        }
        seg->target = 1;
        break;
    case SEG_C:
        seg->load_addr = 0x27FFE00;
        seg->size = 0x160;
        seg->recv_addr = 0x27FFE00;
        seg->target = 0;
        break;
    }
}
