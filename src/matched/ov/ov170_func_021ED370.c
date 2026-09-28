/*
 * function: func_021ED370
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
 *   func_021EBEE0 0x021EBEE0 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ED508 0x021ED508 thumb
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

extern void *func_021EBEE0(char *w, const Desc *s);
extern void func_021EC000(char *p, int i, int v);
extern void func_021ED508(unsigned char *p, int a, int b);
typedef struct {
    Desc a[13];
    Desc b[6];
    Desc c[6];
    Desc d[3];
} DescTable;

extern const DescTable d_021EFD80;

#define WORK(p) (*(char **)((p) + 0x2C))
#define CELL(w, k) (*(void **)((w) + (k) * 4 + 0x9E74))

void func_021ED370(unsigned char *p)
{
    char *w = WORK(p);
    unsigned i;

    CELL(w, 0) = func_021EBEE0(w, &d_021EFD80.a[0]);
    CELL(w, 1) = func_021EBEE0(w, &d_021EFD80.a[1]);
    CELL(w, 2) = func_021EBEE0(w, &d_021EFD80.a[2]);
    CELL(w, 3) = func_021EBEE0(w, &d_021EFD80.a[3]);
    CELL(w, 4) = func_021EBEE0(w, &d_021EFD80.a[4]);
    CELL(w, 5) = func_021EBEE0(w, &d_021EFD80.a[5]);
    CELL(w, 10) = func_021EBEE0(w, &d_021EFD80.a[10]);
    CELL(w, 6) = func_021EBEE0(w, &d_021EFD80.a[6]);
    CELL(w, 7) = func_021EBEE0(w, &d_021EFD80.a[7]);
    CELL(w, 8) = func_021EBEE0(w, &d_021EFD80.a[8]);
    CELL(w, 9) = func_021EBEE0(w, &d_021EFD80.a[9]);
    for (i = 0; i < 6; i++) {
        *(void **)(w + i * 4 + 0x9EA8) = func_021EBEE0(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x138)));
        *(void **)(w + i * 4 + 0x9EC0) = func_021EBEE0(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x1C8)));
    }
    CELL(w, 25) = func_021EBEE0(w, &d_021EFD80.d[0]);
    CELL(w, 26) = func_021EBEE0(w, &d_021EFD80.d[1]);
    CELL(w, 27) = func_021EBEE0(w, &d_021EFD80.d[2]);
    func_021EC000(w, 5, 0);
    func_021EC000(w, 10, 0);
    func_021EC000(w, 0x19, 0);
    func_021EC000(w, 0x1A, 0);
    func_021EC000(w, 0x1B, 0);
    func_021ED508(p, 0xE, 1);
}
