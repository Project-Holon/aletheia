/*
 * function: func_021B9B98
 * address: 0x021B9B98
 * packet: pkt_ov181_021B9B98
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Match lever: integer byte arithmetic for the next 16-byte entry avoids
 * folding the index increment into the current entry pointer.
 * symbols:
 *   BMP_Create 0x02043678 arm
 */
typedef struct { unsigned text; unsigned short tag; unsigned char kind, pad7; unsigned pad8, padC; } Entry;
typedef unsigned int   u32;
struct Bmp;
typedef unsigned short u16;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
#define COUNT(p) (*(unsigned short *)((p) + 0x2B8))
#define ENTRIES(p) (*(Entry **)((p) + 0x2D4))
void func_021B9B98(char *p)
{
    unsigned short i;
    int found = 0;
    for (i = 0; ; i++) {
        Entry *e = &ENTRIES(p)[i];
        if (found == 0) {
            if (e->kind == 7)
                found = 1;
        } else {
            if (e->kind == 5)
                break;
            if (e->kind == 0 && e->text != 0xFFFF && ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->tag == 0 &&
                ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->kind == 0 && ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->text != 0xFFFF) {
                *(void **)(p + COUNT(p) * 8 + 0xB8) = BMP_Create(0x20, 2, 0x20, 0x8E);
                *(int *)(p + COUNT(p) * 8 + 0xBC) = i;
                COUNT(p)++;
                if (COUNT(p) == 0x40)
                    break;
                i++;
            }
        }
    }
}
