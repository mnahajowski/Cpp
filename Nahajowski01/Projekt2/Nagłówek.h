#pragma once
const int VALUE_CHANGER = 5;

void v_alloc_table_add_5(int i_Size);
bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);
bool testing_correct(int number);

