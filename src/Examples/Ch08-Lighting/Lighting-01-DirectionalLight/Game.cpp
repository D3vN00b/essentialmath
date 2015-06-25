//===============================================================================
// @ Game.cpp
// ------------------------------------------------------------------------------
// Game core routines
//
// Copyright (C) 2008 by Elsevier, Inc. All rights reserved.
//
//
//
//===============================================================================

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include <IvRendererHelp.h>

#include "Game.h"
#include "Player.h"

//-------------------------------------------------------------------------------
//-- Static Members -------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Methods --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ IvGame::Create()
//-------------------------------------------------------------------------------
// Static constructor
//-------------------------------------------------------------------------------
bool
IvGame::Create()
{
    IvGame::mGame = new Game();
    return ( IvGame::mGame != 0 );

}   // End of IvGame::Create()


//-------------------------------------------------------------------------------
// @ Game::Game()
//-------------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------------
Game::Game() : IvGame()
{
    // init variables
    mPlayer = 0;            // main player object

}   // End of Game::Game()


//-------------------------------------------------------------------------------
// @ Game::~Game()
//-------------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------------
Game::~Game()
{
    delete mPlayer;
    mPlayer = 0;

}   // End of Game::~Game()


//-------------------------------------------------------------------------------
// @ Game::Initialize()
//-------------------------------------------------------------------------------
// Set up internal subsystems
//-------------------------------------------------------------------------------
bool 
Game::PostRendererInitialize()
{
    // Set up base class 
    IvGame::PostRendererInitialize();
    
    mPlayer = new Player();
    if (!mPlayer)
        return false;

    return true;
}   // End of Game::Initialize()


//-------------------------------------------------------------------------------
// @ Game::Update()
//-------------------------------------------------------------------------------
// Main update loop
//-------------------------------------------------------------------------------
void
Game::UpdateObjects( float dt )
{
    // update player
    mPlayer->Update( dt );
    
}   // End of Game::Update()


//-------------------------------------------------------------------------------
// @ Game::Render()
//-------------------------------------------------------------------------------
// Render stuff
//-------------------------------------------------------------------------------
void 
Game::Render() // Here's Where We Do All The Drawing
{   
    // look from (-10, 2, 10) at the origin of the world 
    IvSetDefaultViewer(0.0f, -20.0f, 0.0f);
    
    // draw axes
//    IvDrawAxes();
    
    // draw the main object
    mPlayer->Render();

} // End of Game::Render()

