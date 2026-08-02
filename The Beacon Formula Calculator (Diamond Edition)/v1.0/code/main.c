#include "BeaconFormula.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char inph[64] = ""; // Input for layer height
    char inpL[64] = ""; // Input for length
    char inpW[64] = ""; // Input for width
    char inpm[64] = ""; // Input for maxmimum layer

    int activeBox = 0;

    char outb_l[64];
    char outb[64];

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window *window = SDL_CreateWindow(
        "The Beacon Formula Calculator (Diamond Edition)", 
        1674, 
        1100, 
        SDL_WINDOW_RESIZABLE
    );

    SDL_Surface *icon = SDL_LoadBMP("image/icon.bmp");
    SDL_SetWindowIcon(window, icon);
    SDL_DestroySurface(icon);

    SDL_StartTextInput(window); // Start text input for the window

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL); //Create renderer

    SDL_FRect boxh = {20, 600, 500, 40}; //Box for layer height input
    SDL_FRect boxL = {20, 650, 500, 40}; //Box for length input
    SDL_FRect boxW = {20, 700, 500, 40}; //Box for width input
    SDL_FRect boxm = {20, 750, 500, 40}; //Box for maximum layer input

    SDL_FRect BeaconLayerFormula
        = {1023, 0, 652, 367}; //BeaconLayerFormula image sizing

    SDL_FRect BeaconFormula
        = {0, 0, 1022, 575}; //BeaconFormula image sizing

    SDL_FRect CalculateBox
        = {20, 820, 60, 60}; //Calculate button
    
    SDL_FRect boxb_l = {20, 900, 500, 40}; //Box for beacon layer output
    SDL_FRect boxb = {20, 950, 500, 40}; //Box for beacon output

    TTF_Font *font = TTF_OpenFont("font/Minecraft.ttf", 32); //Minecraft font

    SDL_Color colour = {255, 255, 255, 255}; //White colour for the text

    SDL_Surface *textSurfaceh =
        TTF_RenderText_Blended(
            font,
            "h = ",
            0,
            colour
        ); //Create surface with the rendered h =  text
    
    SDL_Surface *textSurfaceL =
        TTF_RenderText_Blended(
            font,
            "L = ",
            0,
            colour
        ); //Create surface with the rendered L =  text

    SDL_Surface *textSurfaceW =
        TTF_RenderText_Blended(
            font,
            "W = ",
            0,
            colour
        ); //Create surface with the rendered W =  text
    
    SDL_Surface *textSurfacem =
        TTF_RenderText_Blended(
            font,
            "m = ",
            0,
            colour
        ); //Create surface with the rendered m =  text
    
    
    SDL_Surface *textSurfaceINPh =
        TTF_RenderText_Blended(
            font,
            inph,
            0,
            colour
        ); //Create surface with the rendered inph text
    
    SDL_Surface *textSurfaceINPL =
        TTF_RenderText_Blended(
            font,
            inpL,
            0,
            colour
        ); //Create surface with the rendered inpL text
    
    SDL_Surface *textSurfaceINPW =
        TTF_RenderText_Blended(
            font,
            inpW,
            0,
            colour
        ); //Create surface with the rendered inpW text

    SDL_Surface *textSurfaceINPm =
        TTF_RenderText_Blended(
            font,
            inpm,
            0,
            colour
        ); //Create surface with the rendered inpm text

    SDL_Surface *textSurfaceCalculate = 
        TTF_RenderText_Blended(
            font,
            "=",
            0,
            colour
        ); //Create surface with the rendered calculate text

    SDL_Surface *textSurfaceb_l = 
        TTF_RenderText_Blended(
            font,
            "b_l = ",
            0,
            colour
        ); //Create surface with the rendered b_l text

    SDL_Surface *textSurfaceb = 
        TTF_RenderText_Blended(
            font,
            "b = ",
            0,
            colour
        ); //Create surface with the rendered b text


    SDL_Texture *textTextureh = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceh
        ); //Create a texture from h text surface

    SDL_Texture *textTextureL = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceL
        ); //Create a texture from L text surface
    
    SDL_Texture *textTextureW = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceW
        ); //Create a texture from W text surface
    
    SDL_Texture *textTexturem = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfacem
        ); //Create a texture from m text surface

    
    SDL_Texture *textTextureINPh = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceINPh
        ); //Create a texture from INPh text surface
    
    SDL_Texture *textTextureINPL = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceINPL
        ); //Create a texture from INPL text surface
    
    SDL_Texture *textTextureINPW = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceINPW
        ); //Create a texture from INPW text surface
    
    SDL_Texture *textTextureINPm = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceINPm
        ); //Create a texture from INPm text surface
    
    SDL_Texture *textTextureCalculate = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceCalculate
        ); //Create a texture from Calculate text surface
    
    SDL_Texture *textTextureb_l = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceb_l
        ); //Create a texture from b_l text surface
    
    SDL_Texture *textTextureb = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceb
        ); //Create a texture from b text surface

    SDL_Texture *textureoutputb_l = NULL; 
    SDL_Texture *textureoutputb = NULL;


    SDL_FRect OUTh_0 = {30, 600, 45, 30}; //Output h box
    SDL_FRect OUTL = {30, 650, 45, 30}; //Output L box
    SDL_FRect OUTW = {30, 700, 45, 30}; //Output W box
    SDL_FRect OUTm = {30, 750, 45, 30}; //Output m box
    SDL_FRect EQUAL = {30, 820, 30, 30}; //EQUAL
    SDL_FRect BL = {30, 900, 45, 30}; //b_l
    SDL_FRect B = {30, 950, 45, 30}; //b

    float twh, thh, twL, thL, twW, thW, twm, thm;
    SDL_GetTextureSize(textTextureINPh, &twh, &thh);
    SDL_GetTextureSize(textTextureINPL, &twL, &thL);
    SDL_GetTextureSize(textTextureINPW, &twW, &thW);
    SDL_GetTextureSize(textTextureINPm, &twm, &thm);
    
    
    SDL_FRect INPh_0 = {70, 600, twh, thh}; //Input h box
    SDL_FRect INPL = {70, 650, twL, thL}; //Input L box
    SDL_FRect INPW = {70, 700, twW, thW}; //Input W box
    SDL_FRect INPm = {70, 750, twm, thm}; //Input m box

    SDL_Surface *surfaceBeaconLayerFormula = SDL_LoadBMP("image/BeaconLayerFormula.bmp");  //Load BeaconLayerFormula.bmp as a surface
    SDL_Surface *surfaceBeaconFormula = SDL_LoadBMP("image/BeaconFormula.bmp");  //Load BeaconFormula.bmp as a surface
    
    SDL_Texture *textureBeaconLayerFormula = 
        SDL_CreateTextureFromSurface(
            renderer,
            surfaceBeaconLayerFormula
        ); //Create a texture from BeaconLayerFormula.bmp surface
    
    SDL_Texture *textureBeaconFormula = 
        SDL_CreateTextureFromSurface(
            renderer,
            surfaceBeaconFormula
        ); //Create a texture from BeaconFormula.bmp surface
    
    
    SDL_DestroySurface(textSurfaceh); //Free textSurfaceh surface
    SDL_DestroySurface(textSurfaceL); //Free textSurfaceL surface
    SDL_DestroySurface(textSurfaceW); //Free textSurfaceW surface
    SDL_DestroySurface(textSurfacem); //Free textSurfacem surface
    SDL_DestroySurface(textSurfaceINPh); //Free textSurfaceINPh surface
    SDL_DestroySurface(textSurfaceINPL); //Free textSurfaceINPL surface
    SDL_DestroySurface(textSurfaceINPW); //Free textSurfaceINPW surface
    SDL_DestroySurface(textSurfaceINPm); //Free textSurfaceINPm surface
    SDL_DestroySurface(textSurfaceCalculate); //Free textSurfaceCalculate surface
    SDL_DestroySurface(textSurfaceb_l); //Free textSurfaceb_l surface
    SDL_DestroySurface(textSurfaceb); //Free textSurfaceb surface
    SDL_DestroySurface(surfaceBeaconLayerFormula); //Free surfaceBeaconLayerFormula surface
    SDL_DestroySurface(surfaceBeaconFormula); //Free surfaceBeaconFormula surface
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //Windows background is white
    SDL_RenderClear(renderer); // Clear the renderer

    int running = 1;
    SDL_Event event;

    while(running) {

        while(SDL_PollEvent(&event)) {

            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        
            int w, h;
            SDL_GetWindowSize(window, &w, &h);

            float sx = w/1674.0f;
            float sy = h/1100.f;

            boxh.x = 20 * sx;
            boxh.y = 600 * sy;
            boxh.w = 500 * sx;
            boxh.h = 40 * sy;

            boxL.x = 20 * sx;
            boxL.y = 650 * sy;
            boxL.w = 500 * sx;
            boxL.h = 40 * sy;
            
            boxW.x = 20 * sx;
            boxW.y = 700 * sy;
            boxW.w = 500 * sx;
            boxW.h = 40 * sy;

            boxm.x = 20 * sx;
            boxm.y = 750 * sy;
            boxm.w = 500 * sx;
            boxm.h = 40 * sy;
            
            BeaconLayerFormula.x = 1023 * sx;
            BeaconLayerFormula.w = 652 * sx;
            BeaconLayerFormula.h = 367 * sy;

            BeaconFormula.w = 1022 * sx;
            BeaconFormula.h = 575 * sy;

            CalculateBox.x = 20 * sx;
            CalculateBox.y = 820 * sy;
            CalculateBox.w = 60 * sx;
            CalculateBox.h = 60 * sy;

            boxb_l.x =  20 * sx;
            boxb_l.y = 900 * sy;
            boxb_l.w = 500 * sx;
            boxb_l.h = 40 * sy;

            boxb.x =  20 * sx;
            boxb.y = 950 * sy;
            boxb.w = 500 * sx;
            boxb.h = 40 * sy;

            OUTh_0.x = 30 * sx;
            OUTh_0.y = 600 * sy;

            OUTL.x = 30 * sx;
            OUTL.y = 650 * sy;

            OUTW.x = 30 * sx;
            OUTW.y = 700 * sy;

            OUTm.x = 30 * sx;
            OUTm.y = 750 * sy;

            EQUAL.x = 30 * sx;
            EQUAL.y = 820 * sy;

            BL.x = 30 * sx;
            BL.y = 900 * sy;

            B.x = 30 * sx;
            B.y = 950 * sy;

            INPh_0.x = 70 * sx;
            INPh_0.y = 600 * sy;

            INPL.x = 70 * sx;
            INPL.y = 650 * sy;

            INPW.x = 70 * sx;
            INPW.y = 700 * sy;

            INPm.x = 70 * sx;
            INPm.y = 750 * sy;

            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                float mx = event.button.x;
                float my = event.button.y;
                
                if (mx >= boxh.x && mx <= boxh.x + boxh.w &&
                    my >= boxh.y && my <= boxh.y + boxh.h) {
                    
                        activeBox = 0;

                } else if (mx >= boxL.x && mx <= boxL.x + boxL.w &&
                    my >= boxL.y && my <= boxL.y + boxL.h) {
                        
                        activeBox = 1;
            
                } else if (mx >= boxW.x && mx <= boxW.x + boxW.w &&
                    my >= boxW.y && my <= boxW.y + boxW.h) {
                        
                        activeBox = 2;
            
                } else if (mx >= boxm.x && mx <= boxm.x + boxm.w &&
                    my >= boxm.y && my <= boxm.y + boxm.h) {
                        
                        activeBox = 3;
                }
            }
            
            
            
            if (event.type == SDL_EVENT_TEXT_INPUT) {
                
                if (activeBox == 0) {
                    strcat(inph, event.text.text);
                } else if (activeBox == 1) {
                    strcat(inpL, event.text.text);
                } else if (activeBox == 2) {
                    strcat(inpW, event.text.text);
                } else if (activeBox == 3) {
                    strcat(inpm, event.text.text);
                }
            }

            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_BACKSPACE) {

                    if (activeBox == 0) {

                        int lenh = strlen(inph);
                        
                        if (lenh > 0) {

                            inph[lenh - 1] = '\0';
                        }

                    } else if (activeBox == 1) {

                        int lenL = strlen(inpL);
                        
                        if (lenL > 0) {

                            inpL[lenL - 1] = '\0';
                        }

                    } else if (activeBox == 2) {

                        int lenW = strlen(inpW);
                        
                        if (lenW > 0) {

                            inpW[lenW - 1] = '\0';
                        }

                    } else if (activeBox == 3) {

                        int lenm = strlen(inpm);
                        
                        if (lenm > 0) {

                            inpm[lenm - 1] = '\0';
                        }
                    }
                   
                }
            }
        

            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                float mx = event.button.x;
                float my = event.button.y;
                
                if (mx >= CalculateBox.x && mx <= CalculateBox.x + CalculateBox.w &&
                    my >= CalculateBox.y && my <= CalculateBox.y + CalculateBox.h) {
                        
                        int h_0 = atoi(inph);
                        int L = atoi(inpL);
                        int W = atoi(inpW);
                        int m = atoi(inpm);
                        /*From string to an integer*/

                        sprintf(outb_l, "%d", b_l(h_0, L, W));
                        sprintf(outb, "%d", b(L, W, m));

                        SDL_Surface *outputb_l = 
                            TTF_RenderText_Blended(
                                font,
                                outb_l,
                                0,
                                colour
                            ); //Create surface with the rendered outb_l text
                        
                        textureoutputb_l = 
                            SDL_CreateTextureFromSurface(
                                renderer,
                                outputb_l
                            ); //Create a texture from outb_l text surface

                        SDL_FRect txtb_l;
                        txtb_l.x = 120;
                        txtb_l.y = 900;
                        txtb_l.w = outputb_l->w;
                        txtb_l.h = outputb_l->h;

                        SDL_DestroySurface(outputb_l);

                        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
                        SDL_RenderFillRect(renderer, &txtb_l); //Render boxb_l

                        SDL_RenderTexture(
                            renderer,
                            textureoutputb_l,
                            NULL,
                            &txtb_l
                        );


                        SDL_Surface *outputb = 
                            TTF_RenderText_Blended(
                                font,
                                outb,
                                0,
                                colour
                            ); //Create surface with the rendered outb text
                        
                        textureoutputb = 
                            SDL_CreateTextureFromSurface(
                                renderer,
                                outputb
                            ); //Create a texture from outb text surface

                        SDL_FRect txtb;
                        txtb.x = 120;
                        txtb.y = 950;
                        txtb.w = outputb->w;
                        txtb.h = outputb->h;

                        SDL_DestroySurface(outputb);
                        

                        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
                        SDL_RenderFillRect(renderer, &txtb); //Render boxb

                        SDL_RenderTexture(
                            renderer,
                            textureoutputb,
                            NULL,
                            &txtb
                        );
                    
                }
            
            }

        }

        SDL_DestroySurface(textSurfaceINPh); //Free textSurfaceINPh surface
        SDL_DestroySurface(textSurfaceINPL); //Free textSurfaceINPL surface
        SDL_DestroySurface(textSurfaceINPW); //Free textSurfaceINPW surface
        SDL_DestroySurface(textSurfaceINPm); //Free textSurfaceINPm surface

        textSurfaceINPh =
        TTF_RenderText_Blended(
            font,
            inph,
            0,
            colour
        ); //Create surface with the rendered inph text
        
        textSurfaceINPL =
        TTF_RenderText_Blended(
            font,
            inpL,
            0,
            colour
        ); //Create surface with the rendered inpL text
    
        textSurfaceINPW =
        TTF_RenderText_Blended(
            font,
            inpW,
            0,
            colour
        ); //Create surface with the rendered inpW text

        textSurfaceINPm =
        TTF_RenderText_Blended(
            font,
            inpm,
            0,
            colour
        ); //Create surface with the rendered inpm text

        textTextureINPh = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceINPh
        ); //Create a texture from INPh text surface
    
       textTextureINPL = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceINPL
        ); //Create a texture from INPL text surface
    
        textTextureINPW = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceINPW
        ); //Create a texture from INPW text surface
    
        textTextureINPm = 
        SDL_CreateTextureFromSurface(
            renderer,
            textSurfaceINPm
        ); //Create a texture from INPm text surface */


        SDL_FRect OUTh_0 = {30, 600, 45, 30}; //Output h box
        SDL_FRect OUTL = {30, 650, 45, 30}; //Output L box
        SDL_FRect OUTW = {30, 700, 45, 30}; //Output W box
        SDL_FRect OUTm = {30, 750, 45, 30}; //Output m box
        SDL_FRect EQUAL = {30, 820, 30, 30}; //EQUAL
        SDL_FRect BL = {30, 900, 45, 30}; //b_l
        SDL_FRect B = {30, 950, 45, 30}; //b

        float twh, thh, twL, thL, twW, thW, twm, thm;
        SDL_GetTextureSize(textTextureINPh, &twh, &thh);
        SDL_GetTextureSize(textTextureINPL, &twL, &thL);
        SDL_GetTextureSize(textTextureINPW, &twW, &thW);
        SDL_GetTextureSize(textTextureINPm, &twm, &thm);
        
        
        SDL_FRect INPh_0 = {70, 600, twh, thh}; //Input h box
        SDL_FRect INPL = {70, 650, twL, thL}; //Input L box
        SDL_FRect INPW = {70, 700, twW, thW}; //Input W box
        SDL_FRect INPm = {70, 750, twm, thm}; //Input m box


        int w, h;
        SDL_GetWindowSize(window, &w, &h);

        float sx = w/1674.0f;
        float sy = h/1100.f;

        OUTh_0.x = 30 * sx;
        OUTh_0.y = 600 * sy;

        OUTL.x = 30 * sx;
        OUTL.y = 650 * sy;

        OUTW.x = 30 * sx;
        OUTW.y = 700 * sy;

        OUTm.x = 30 * sx;
        OUTm.y = 750 * sy;

        EQUAL.x = 30 * sx;
        EQUAL.y = 820 * sy;

        BL.x = 30 * sx;
        BL.y = 900 * sy;

        B.x = 30 * sx;
        B.y = 950 * sy;

        INPh_0.x = 70 * sx;
        INPh_0.y = 600 * sy;

        INPL.x = 70 * sx;
        INPL.y = 650 * sy;

        INPW.x = 70 * sx;
        INPW.y = 700 * sy;

        INPm.x = 70 * sx;
        INPm.y = 750 * sy;

        
        SDL_FRect txtb_l;
        txtb_l.x = 120 * sx;
        txtb_l.y = 900 * sy;
        txtb_l.w = 45;
        txtb_l.h = 30;

        SDL_FRect txtb;
        txtb.x = 120 * sx;
        txtb.y = 950 * sy;
        txtb.w = 45;
        txtb.h = 30;
        
    
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //Windows background is white
        SDL_RenderClear(renderer); // Clear the renderer

        
        SDL_RenderTexture(
            renderer,
            textureBeaconLayerFormula,
            NULL,
            &BeaconLayerFormula
        ); //Render BeaconLayerFormula.bmp texture to the renderer

        SDL_RenderTexture(
            renderer,
            textureBeaconFormula,
            NULL,
            &BeaconFormula
        ); //Render BeaconFormula.bmp texture to the renderer
    
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &boxh); //Render boxh
        SDL_RenderTexture(
            renderer,
            textTextureh,
            NULL,
            &OUTh_0
        ); //Render h texture to the renderer

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &boxL); //Render boxL
        SDL_RenderTexture(
            renderer,
            textTextureL,
            NULL,
            &OUTL
        ); //Render L texture to the renderer

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &boxW); //Render boxW
        SDL_RenderTexture(
            renderer,
            textTextureW,
            NULL,
            &OUTW
        ); //Render W texture to the renderer

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &boxm); //Render boxm
        SDL_RenderTexture(
            renderer,
            textTexturem,
            NULL,
            &OUTm
        ); //Render m texture to the renderer

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &CalculateBox); //Render CalculateBox
        SDL_RenderTexture(
            renderer,
            textTextureCalculate,
            NULL,
            &EQUAL
        ); //Render "=" texture to the renderer

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &boxb_l); //Render boxb_l
        SDL_RenderTexture(
            renderer,
            textTextureb_l,
            NULL,
            &BL
        ); //Render b_l texture to the renderer

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &boxb); //Render boxb
        SDL_RenderTexture(
            renderer,
            textTextureb,
            NULL,
            &B
        ); //Render b texture to the renderer
        
        SDL_RenderTexture(
            renderer,
            textTextureINPh,
            NULL,
            &INPh_0
        ); //Render INPh texture to the renderer

       SDL_RenderTexture(
            renderer,
            textTextureINPL,
            NULL,
            &INPL
        ); //Render INPL texture to the renderer

        SDL_RenderTexture(
            renderer,
            textTextureINPW,
            NULL,
            &INPW
        ); //Render INPW texture to the renderer

        SDL_RenderTexture(
            renderer,
            textTextureINPm,
            NULL,
            &INPm
        ); //Render INPm texture to the renderer

    if (textureoutputb_l){
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &txtb_l); //Render boxb_l
        SDL_RenderTexture(
            renderer,
            textureoutputb_l,
            NULL,
            &txtb_l
        );
    
    } 
    
    if (textureoutputb) {

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Blue
        SDL_RenderFillRect(renderer, &txtb); //Render boxb_l
        SDL_RenderTexture(
            renderer,
            textureoutputb,
            NULL,
            &txtb
        );
    }

        SDL_RenderPresent(renderer); // Update the screen with the rendered content
    }
    
    SDL_DestroyTexture(textureBeaconLayerFormula); //Free the BeaconLayerFormula.bmp texture
    SDL_DestroyTexture(textureBeaconFormula); //Free the BeaconFormula.bmp texture
    SDL_DestroyTexture(textTextureh); //Free h texture
    SDL_DestroyTexture(textTextureL); //Free L texture
    SDL_DestroyTexture(textTextureW); //Free W texture
    SDL_DestroyTexture(textTexturem); //Free m texture
    SDL_DestroyTexture(textTextureCalculate); //Free "=" texture
    SDL_DestroyTexture(textTextureb_l); //Free b_l texture
    SDL_DestroyTexture(textTextureb); //Free b texture
    SDL_DestroyTexture(textTextureINPh); //Free INPh texture
    SDL_DestroyTexture(textTextureINPL); //Free INPL texture
    SDL_DestroyTexture(textTextureINPW); //Free INPW texture
    SDL_DestroyTexture(textTextureINPm); //Free INPm texture
    TTF_CloseFont(font); //Close the font
    SDL_DestroyRenderer(renderer); //Destroy the renderer
    SDL_DestroyWindow(window); //Destroy the window
    TTF_Quit();
    SDL_Quit();

    return 0;
}