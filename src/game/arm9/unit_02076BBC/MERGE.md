# unit_02076BBC (arm9)

Parts unit_02076BBC_p01.c, p02.c plus members CARDi_ReadRom.c, func_0207733C.c.

Blocked by CARD structs defined with different bodies per member (CARDiRomState, CARDiCommon, CARDDmaInterface redefined or redeclared as anonymous structs). Give each one definition (field offsets must agree), then merge in address order.
