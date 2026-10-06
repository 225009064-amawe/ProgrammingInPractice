#ifndef STORAGE_H
#define STORAGE_H


int  save_employees_text(void);
int  load_employees_text(void);
int  save_suppliers_text(void);
int  load_suppliers_text(void);
int  save_assets_text(void);
int  load_assets_text(void);
int  save_budget_text(void);
int  load_budget_text(void);


int  save_employees_binary(void);
int  load_employees_binary(void);


int  save_all_text(void);
int  load_all_text(void);
int  ensure_data_dir(void);

#endif