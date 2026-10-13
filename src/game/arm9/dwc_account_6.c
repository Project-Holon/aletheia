/*
 * file:     dwc_account_6.c
 * unit:     yes
 * function: DWCi_Acc_SetPlayerId, DWCi_Acc_SetFriendKey, DWCi_Acc_SetGsProfileId
 * address:  0x020590F0
 * packet:   pkt_020590F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef struct S {
    int pad;
    int a;
    int b;
} S;

void DWCi_Acc_SetPlayerId(int *p, int v)
{
    p[2] = v;
}

void DWCi_Acc_SetFriendKey(S *p, int a, int b)
{
    p->a = a;
    p->b = b;
}

void DWCi_Acc_SetGsProfileId(int *p, int v)
{
    p[1] = v;
}
