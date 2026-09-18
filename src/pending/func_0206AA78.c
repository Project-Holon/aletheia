/*
 * function: func_0206AA78
 * address:  0x0206AA78
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  02148BF4
 * symbols:
 *   g_02148B4C      0x02148B4C  data
 *   g_02148C2C      0x02148C2C  data
 *   g_02148C38      0x02148C38  data
 *   g_02148BF4      0x02148BF4  data
 *   g_02148B54      0x02148B54  data
 *   g_02148D0C      0x02148D0C  data
 */

extern int g_02148BF4[];
void func_0206AA78(int idx, int v)
{
    g_02148BF4[idx] = v | (idx << 30);
}
