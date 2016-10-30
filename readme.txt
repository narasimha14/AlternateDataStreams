This is a Windows virus that makes use of the Alternate Data Streams(ADS) feature in the Windows Operating Systems.
It is a harmless polymorphic virus. Polymorphism is achieved by XORing with the name of the file to be infected as the key.

Execution:

Compile wrapper.c, xorcipher.c, virus.c and the oldprogram.c files and create the corresponding executables.

Get the CS.exe file from http://www.flexhex.com/docs/articles/alternate-streams.phtml. This is a utility to copy the data stream in attached to any file. This is necessary to fetch the encrypted virus stream and to decrypt it and run it.

Get the streams.exe file from http://technet.microsoft.com/en-us/sysinternals/bb897440.aspx. This is a utility provided by windows to find out all of the streams attached to a file. It is required in order to avoid infecting the already infected file. 

Get all the above exe files in one folder and run wrapper.bat in the same folder. It attaches all the necessary exe files as streams to the wrapper.exe.

Run this wrapper.exe file and you can see that it infects one more uninfected exe file in that folder, and after the infection it runs the oldprogram.exe.
