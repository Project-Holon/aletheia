/*
 * file:     unit_02176DEC_p03.c
 * unit:     yes
 * function: func_021770EC, func_02177138
 * address:  0x021770EC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCs_GetTransConnection  0x02177770 arm
 *   DWCs_GetRecvState        0x021777A4 arm
 *   g_021AB180  0x021AB180  data
 */
extern void *DWCs_GetTransConnection(unsigned char aid);
extern int DWCs_GetRecvState(unsigned char aid);
int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size);
int func_02177138(int a, int b);
extern char g_021AB180[];


int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size)
{
    char *connection = DWCs_GetTransConnection(aid);

    if (DWCs_GetRecvState(aid) == 2)
        return 0;
    *(void **)(connection + 4) = recvBuffer;
    *(int *)(connection + 8) = size;
    *(char *)(connection + 0x1d) = 1;
    *(int *)(connection + 0x10) = 0;
    *(int *)(connection + 0x18) = 0;
    return 1;
}


/*
 * Word at +0x700 of the block the module pointer holds, and the block again at
 * +0x710 of the second copy the pointer holds, or zero when there is no block.
 */
int func_02177138(int a, int b)
{
    int *p = *(int **)g_021AB180;

    if (p == 0)
        return 0;
    *(int *)((char *)p + 0x700) = a;
    *(int *)((char *)*(int **)g_021AB180 + 0x710) = b;
    return 1;
}
