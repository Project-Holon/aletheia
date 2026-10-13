/*
 * function: DWCi_Acc_IsValidLoginId
 * address:  0x020596B0
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The ARM9 listing labels this address DWCi_Acc_IsValidLoginId; it calls DWCi_Acc_GetFlag_DataType, so it is a dwc_account.o static (the SDK table's DWC_GHTTPCleanupRootCAList attribution here does not match the linked bytes).
 */
extern unsigned long DWCi_Acc_GetFlag_DataType(void *loginid);

int DWCi_Acc_IsValidLoginId(void *loginid)
{
    return DWCi_Acc_GetFlag_DataType(loginid) == 1;
}
