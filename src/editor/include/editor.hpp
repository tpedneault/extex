/***************************************************************************************************/
/*                                                                                                 */
/*                       $$$$$$$$\ $$\   $$\ $$$$$$$$\ $$$$$$$$\ $$\   $$\                         */
/*                       $$  _____|$$ |  $$ |\__$$  __|$$  _____|$$ |  $$ |                        */
/*                       $$ |      $$\ $$  |   $$ |   $$ |      $$\ $$  |                          */
/*                       $$$$$\     $$$$  /    $$ |   $$$$$\     $$$$  /                           */
/*                       $$  __|    $$  $$<     $$ |   $$  __|    $$  $$<                          */
/*                       $$ |      $$  /$$\    $$ |   $$ |      $$  /$$\                           */
/*                       $$$$$$$$\ $$ /  $$ |   $$ |   $$$$$$$$\ $$ /  $$ |                        */
/*                       \________|\__|  \__|   \__|   \________|\__|  \__|                        */
/*                                                                                                 */
/***************************************************************************************************/
/* FILE NAME  : editor.hpp                                                                         */
/* DESCRIPTION: Implements the logic of the text editor.                                           */
/* AUTHOR     : Thomas Pedneault                                                                   */
/* DATE       : 2024-02-18                                                                         */
/***************************************************************************************************/

#ifndef EDITOR_H
#define EDITOR_H

#include "component.hpp"
#include "background.hpp"

class Editor : public ComponentPubSub {
public:
    virtual STATUS Initialize();
    virtual STATUS Update();
    virtual STATUS Destroy();
private:
    Background m_background;
};

#endif /* EDITOR_H */
