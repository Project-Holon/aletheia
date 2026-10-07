/*
 * file:     btlv_effvm_p24.c
 * unit:     yes
 * function: func_021F88BC, func_021F88E0
 * address:  0x021F88BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 */
typedef struct {
    char pad[0x1ec];
    unsigned m : 8;
    unsigned lo : 10;
    unsigned v : 8;
    unsigned b26 : 1;
} Work_021F88BC;

typedef struct {
    char pad[0x1ec];
    unsigned lo : 26;
    unsigned b26 : 1;
} Work_021F88E0;

void func_021F88BC(int a);
int func_021F88E0(void);
extern Work_021F88BC *d_0220AF20;


/*
 * Sets flag bit 26 of the word at 0x1ec of the global work block.
 */
void func_021F88BC(int a)
{
    d_0220AF20->b26 = a;
}


int func_021F88E0(void)
{
    return d_0220AF20->b26;
}
