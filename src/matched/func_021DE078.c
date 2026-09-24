/*
 * function: func_021DE078
 * address:  0x021DE078
 * packet:   pkt_021DE078
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * note:     the listing extent (136 B) runs past this 92-byte body into the
 *           next function's leaf and pool words; every compiled byte matches.
 *
 * symbols:
 *   g_021E3A8C   0x021E3A8C  data
 *   g_021E3B4C   0x021E3B4C  data
 *   g_021E3B54   0x021E3B54  data
 *
 * Object teardown: the object's +8 table supplies the two title strings that
 * get unregistered from the shared group, then the object's own four table
 * words go back to the pool manager.
 */

typedef unsigned int u32;

extern void func_02182AC0(int a, int b, int c, int d);
extern void func_02182CF0(int a, int b, int c, int d);
extern void func_021DDBE4(void *p, int a, int b);
extern u32  g_021E3A8C[];
extern u32  g_021E3B4C[];
extern u32  g_021E3B54[];

int func_021DE078(int *p)
{
    int *q = (int *)p[2];

    func_02182AC0(p[6], (int)g_021E3A8C, (int)g_021E3B4C, q[0]);
    func_02182CF0(p[6], (int)g_021E3A8C, (int)g_021E3B54, q[1]);
    func_021DDBE4(p, q[2], q[3]);
    return 0;
}
