driverName = input('Enter name of the Driver')

driverFiles = ['_interface.h','_config.h','_register.h','_private.h','_program.c']

for i in driverFiles:
  file=open(driverName.upper()+i,'w')
  if i[-1] == 'h' :
    i=i[:-2]
    i=i.upper()
    file.write('#ifndef ' + driverName + i + '_H_' + '\n' )
    file.write('#define ' + driverName + i + '_H_' + '\n')
    file.write('#endif ')
  elif i[-1] == 'c' :
    i=i[:-2]
    i=i.upper()
    file.write('#include "'+driverName.upper()+'_config.h"'+ '\n' )
    file.write('#include "'+driverName.upper()+'_private.h"'+ '\n')
    file.write('#include "'+driverName.upper()+'_register.h"'+'\n')
    file.write('#include "'+driverName.upper()+'_interface.h"'+'\n')


