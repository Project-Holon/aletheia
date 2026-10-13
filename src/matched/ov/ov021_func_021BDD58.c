/*
 * function: ENTRANCE_CAMERA_AllocWork
 * address:  0x021BDD58
 * packet:   pkt_ov021_021BDD58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gEntranceCameraFileName     0x021DE37C  data  a4
 */

extern int gEntranceCameraFileName;

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);

void *ENTRANCE_CAMERA_AllocWork(int a)
{
    return func_02030734(a, 0x70, 0, (const char *)&gEntranceCameraFileName, 0x12A);
}
