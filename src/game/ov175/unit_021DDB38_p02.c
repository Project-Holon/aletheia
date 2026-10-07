/*
 * file:     unit_021DDB38_p02.c
 * unit:     yes
 * function: func_021DE024, func_021DE038, func_021DE078
 * address:  0x021DE024
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E39A0  0x021E39A0  data
 *   func_021DDB38  0x021DDB38  arm
 *   g_021E3A8C   0x021E3A8C  data
 *   g_021E3B4C   0x021E3B4C  data
 *   g_021E3B54   0x021E3B54  data
 */
struct SAKEField;
struct SAKERequestInternal;
typedef unsigned int u32;

extern int func_021DDB10(void *, int);
extern int func_021DDB38(char **names, int n);
extern void func_02182AC0(int a, int b, int c, int d);
extern void func_02182CF0(int a, int b, int c, int d);
extern void func_021DDBE4(struct SAKERequestInternal *request, struct SAKEField *fields, int numFields);
void func_021DE024(void *p);
int func_021DE038(char *p);
int func_021DE078(int *p);
extern char d_021E39A0[];
extern u32  g_021E3A8C[];
extern u32  g_021E3B4C[];
extern u32  g_021E3B54[];


void func_021DE024(void *p)
{
    func_021DDB10(p, (int)d_021E39A0);
}


/*
 * Pre-flight check of the +0x08 block: a missing head or an empty count is
 * rejected with 4, a non-positive count with 6, a missing name table with 5;
 * otherwise the table is checked word by word by func_021DDB38.
 */
int func_021DE038(char *p)
{
    int *q = *(int **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[3] <= 0)
        return 6;
    if (q[2] == 0)
        return 5;
    return func_021DDB38((char **)q[2], q[3]);
}


/*
 * note:     the listing extent (136 B) runs past this 92-byte body into the
 *           next function's leaf and pool words; every compiled byte matches.
 *
 * Object teardown: the object's +8 table supplies the two title strings that
 * get unregistered from the shared group, then the object's own four table
 * words go back to the pool manager.
 */
int func_021DE078(int *p)
{
    int *q = (int *)p[2];

    func_02182AC0(p[6], (int)g_021E3A8C, (int)g_021E3B4C, q[0]);
    func_02182CF0(p[6], (int)g_021E3A8C, (int)g_021E3B54, q[1]);
    func_021DDBE4((struct SAKERequestInternal *)p, (struct SAKEField *)q[2], q[3]);
    return 0;
}
