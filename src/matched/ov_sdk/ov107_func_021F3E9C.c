/*
 * function: func_021F3E9C
 * address:  0x021F3E9C
 * packet:   pkt_ov107_021F3E9C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_UpdateGameInfoMember (libmb.TWL.HYB.a(mb_gameinfo.o))
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 */

extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);

void func_021F3E9C(unsigned char *gameInfop, void *member, unsigned short nowPlayerFlag, unsigned short changePlayerFlag)
{
    unsigned char playerNum = 1;
    int i;

    MIi_CpuCopy16(member, gameInfop + 0x35E, 0x14A);
    for (i = 0; i < 15; i++) {
        if (nowPlayerFlag & (2 << i))
            playerNum++;
    }
    gameInfop[0x358] = playerNum;
    *(unsigned short *)(gameInfop + 0x35A) = nowPlayerFlag | 1;
    *(unsigned short *)(gameInfop + 0x35C) = changePlayerFlag;
    ((unsigned char *)gameInfop)[0x4B4] = ((unsigned char *)gameInfop)[0x4B4] + 1;
}
