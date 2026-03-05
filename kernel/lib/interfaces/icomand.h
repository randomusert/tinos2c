#ifndef ICOMMAND_H
#define ICOMMAND_H

typedef struct ICommand {
    const char* name;
    void (*execute)(const char* args);
} ICommand;

#endif // ICOMMAND_H