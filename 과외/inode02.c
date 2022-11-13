
typedef const enum file_type File_type;


typedef struct date Date;

typedef Date* Date_pointer;


typedef struct inode Inode;

typedef Inode* Inode_pointer;


typedef struct data_byte Date_byte;

typedef Date_byte* Date_byte_pointer;


typedef struct data_block  Data_block;

typedef Data_block* Data_block_pointer;


typedef struct my_file_system My_file_system;


Date_pointer set_date(void);

Inode_pointer nextInode(void);

Date_byte_pointer nextDataByte(void);

Data_block_pointer nextDatablock(void);