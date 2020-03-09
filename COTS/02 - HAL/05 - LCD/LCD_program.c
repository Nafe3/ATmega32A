/********************************/
/* Author		: Mohamed Nafea */
/* Version		: V01			*/
/* Release Date	: 14-1-2020		*/
/********************************/

/* Description:	This API shall initialize LCD	*/
void CLCD_voidInitialize(void)
{
	/*	wait more than 30 us	*/
	delay_ms(40);
	
	/**/
	CLCD_voidWriteCmd(0b00111000);
	CLCD_voidWriteCmd(0b00001100);
	CLCD_voidWriteCmd(0b00000001);

	delay_ms(2);
}

/*Description : This API shall display data on LCD */
void CLCD_voidWriteData(u8 Copy-u8Data)
{
  /* Set RS = 1 */
  SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN, 1);
  
  /* Set RW = 0 */
  SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN, 0);
  
  /* Set Data on Data Port */
  CLCD_voidSetDataPort(Copy-u8Data);
  
  /* Enable Pulse */
  SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
  delay_ms(1);
  SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
  delay_ms(1);
  
}

static void CLCD_voidSetDataPort(u8 Copy-u8Data)
{
  u8 Local_u8Bit;
  
  Local_u8Bit = GET_BIT(Copy-u8Data,0);
  SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN, Local_u8Bit);
  
  Local_u8Bit = GET_BIT(Copy-u8Data,1);
  SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D1_PIN, Local_u8Bit);
  
  Local_u8Bit = GET_BIT(Copy-u8Data,2);
  SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D2_PIN, Local_u8Bit);
  
  Local_u8Bit = GET_BIT(Copy-u8Data,3);
  SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D3_PIN, Local_u8Bit);
  
  Local_u8Bit = GET_BIT(Copy-u8Data,4);
  SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D4_PIN, Local_u8Bit);
  
  Local_u8Bit = GET_BIT(Copy-u8Data,5);
  SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D5_PIN, Local_u8Bit);
  
  Local_u8Bit = GET_BIT(Copy-u8Data,6);
  SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D6_PIN, Local_u8Bit);
  
  Local_u8Bit = GET_BIT(Copy-u8Data,7);
  SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D7_PIN, Local_u8Bit);
}

/*Description : This API shall execute command on LCD*/
void CLCD_voidWriteCmd(u8 Copy-u8Cmd)
{
  /* Set RS = 0 */
  SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN, 0);
  
  /* Set RW = 0 */
  SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN, 0);
  
  /* Set Data on Data Port */
  CLCD_voidSetDataPort(Copy-u8Data);
  
  /* Enable Pulse */
  SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
  delay_ms(1);
  SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
  delay_ms(1);

}