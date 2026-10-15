/*
 * unit:     no
 * function: GF_STANDARD_Init
 * address:  0x0203EF5C
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469F8     0x021469F8  data
 *   g_020A7E4C     0x020A7E4C  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   MATHi_CRC16InitTable  0x020819B8  arm
 *
 * TU: gf_standard.c.  The allocation site string at 0x020A7E4C reads
 * "gf_standard.c" and this is its only reference in the image, so the
 * Mersenne Twister block (0x0203EF5C onwards) is that translation unit;
 * bg_sys.c starts further down at 0x0203F8F4, whose site string is the
 * "bg_sys.c" at 0x020A7E5C.
 *
 * Constructor for the random-number state: 0xbcc bytes holding mt[624], the
 * generator index (set to 625, "exhausted"), a spare word and the constant
 * 0x9908b0df, then a 0x200-byte buffer at +0x9cc that MATHi_CRC16InitTable
 * initialises.  The allocation tag 49 stays live in r5 afterwards and both
 * later constants are derived from it with a single `add`, which is why
 * neither 625 nor 4129 costs a pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Init.c \
 *       --func GF_STANDARD_Init --addr 0x0203EF5C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Mt {
    u32 mt[624];
    s32 index;
    u32 unk_9c4;
    u32 unk_9c8;
    u8  unk_9cc[0x200];
};

extern struct Mt *g_021469F8;
extern char g_020A7E4C[];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
struct MATHCRC16Table;
extern void MATHi_CRC16InitTable(struct MATHCRC16Table *table, u16 poly);

void GF_STANDARD_Init(u32 heapId)
{
    g_021469F8 = GFL_HEAP_Alloc(heapId, 0xbcc, 0, g_020A7E4C, 49);
    g_021469F8->index = 625;
    g_021469F8->unk_9c4 = 0;
    g_021469F8->unk_9c8 = 0x9908b0df;
    MATHi_CRC16InitTable((struct MATHCRC16Table *)g_021469F8->unk_9cc, 4129);
}
