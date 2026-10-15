/*
 * function: BOX2_SEQ_CreateCursorObjects
 * address:  0x021ED370
 * packet:   pkt_ov170_021ED370
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_CreateActorFromDesc 0x021EBEE0 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb
 *   d_021EFD80 0x021EFD80 data
 *
 * Builds the cell objects of the box screen from the descriptor table
 * at 0x021EFD80 into the work slots at 0x9E74, hides five of them, then
 * refreshes the cursor.  The loop rows are addressed as a byte offset
 * (i * 0x18 + 0x138) from the table base: both the member form .b[i] and
 * the index form [i + 13] fold the row offset into the literal instead.
 */

typedef struct {
    short x;
    short y;
    unsigned char pad4[2];
    unsigned char b6;
    unsigned char b7;
    int a;
    int b;
    int c;
    unsigned short e;
    unsigned short d;
} Desc;

extern void *BOX2_SEQ_CreateActorFromDesc(char *w, const Desc *s);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
typedef struct {
    Desc a[13];
    Desc b[6];
    Desc c[6];
    Desc d[3];
} DescTable;

extern const DescTable d_021EFD80;

#define WORK(p) (*(char **)((p) + 0x2C))
#define CELL(w, k) (*(void **)((w) + (k) * 4 + 0x9E74))

void BOX2_SEQ_CreateCursorObjects(unsigned char *p)
{
    char *w = WORK(p);
    unsigned i;

    CELL(w, 0) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[0]);
    CELL(w, 1) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[1]);
    CELL(w, 2) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[2]);
    CELL(w, 3) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[3]);
    CELL(w, 4) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[4]);
    CELL(w, 5) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[5]);
    CELL(w, 10) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[10]);
    CELL(w, 6) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[6]);
    CELL(w, 7) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[7]);
    CELL(w, 8) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[8]);
    CELL(w, 9) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[9]);
    for (i = 0; i < 6; i++) {
        *(void **)(w + i * 4 + 0x9EA8) = BOX2_SEQ_CreateActorFromDesc(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x138)));
        *(void **)(w + i * 4 + 0x9EC0) = BOX2_SEQ_CreateActorFromDesc(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x1C8)));
    }
    CELL(w, 25) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[0]);
    CELL(w, 26) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[1]);
    CELL(w, 27) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[2]);
    BOX2_SEQ_SetActorDrawEnable(w, 5, 0);
    BOX2_SEQ_SetActorDrawEnable(w, 10, 0);
    BOX2_SEQ_SetActorDrawEnable(w, 0x19, 0);
    BOX2_SEQ_SetActorDrawEnable(w, 0x1A, 0);
    BOX2_SEQ_SetActorDrawEnable(w, 0x1B, 0);
    BOX2_SEQ_SetWindow9(p, 0xE, 1);
}
