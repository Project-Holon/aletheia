/*
 * file:     btlv_effvm_p23.c
 * unit:     yes
 * function: func_021F8884, func_021F88A8
 * address:  0x021F8884
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
    unsigned lo : 18;
    unsigned v : 8;
} Work_021F8884;

typedef struct {
    char pad[0x1ec];
    unsigned m : 8;
    unsigned lo : 10;
    unsigned v : 8;
    unsigned b26 : 1;
} Work_021F88A8;

void func_021F8884(int a);
int func_021F88A8(void);
extern Work_021F8884 *d_0220AF20;


/*
 * Stores the low 8 bits of the argument in bits 18..25 of the word at 0x1ec of the global work block.
 */
void func_021F8884(int a)
{
    d_0220AF20->v = a;
}


/*
 * Returns bits 18..25 of the word at 0x1ec of the global work block.
 */
int func_021F88A8(void)
{
    return d_0220AF20->v;
}
