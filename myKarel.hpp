/*
 * myKarel - v0.1. - 17 / 02 / 2023
 * Author: Manoella Santos Diniz
 */

// lista de dependencias
#include "karel.hpp"

/**
 * Classe para definir robo particular (MyRobot),
 * a partir do modelo generico (Robot)
 *
 * Nota: Todas as definicoes irao valer para qualquer outro robo
 *       criado a partir dessa nova descricao de modelo.
 */
class MyRobot : public Robot
{
public:
    /**
     * turnRight - Procedimento para virar 'a direita.
     */
    void turnRight()
    {
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            for (int i = 0; i < 3; i++)
            {
                turnLeft();
            }
        }
    }

    /**
     * turnAround - Procedimento para dar meia volta.
     */
    void turnAround()
    {
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            for (int i = 0; i < 2; i++)
            {
                turnLeft();
            }
        }
    }

    /**
     * moveN - Metodo para mover certa quantidade de passos.
     * @param steps - passos a serem dados.
     */
    void moveN(int steps)
    {
        // definir dado local
        int step = 0;
        // repetir contando e testando ate' atingir a quantidade de passos
        for (step = 1; step <= steps; step = step + 1) // outra forma de repetir
        {
            // dar um passo por vez
            move();
        }
    }

    /**
     * doPartialTask - Metodo para descrever parte de uma tarefa.
     */
    void doPartialTask()
    {
        // especificar acoes dessa parte da tarefa
        moveN(3);
        turnLeft();
    }

    /**
     * putBeepers - Metodo para colocar varios marcadores de uma so vez.
     * @param n - quantidade de marcadores
     */
    void putBeepers(int n)
    {
        // definir dado local
        int i;

        for (i = 0; i <= n; i++)
        {
            if (beepersInBag())
                putBeeper();
        }
    }

    /**
     * pickBeepers - Metodo para pegar varios marcadores de uma so vez.
     * @param n - quantidade de marcadores
     */
    void pickBeepers(int n)
    {
        // definir dado local
        int i;

        for (i = 0; i <= n; i++)
        {
            if (nextToABeeper())
                pickBeeper();
        }
    }

    /**
     * doTask - Relacao de acoes para qualquer robo executar.
     */
    void doTask()
    {
        // definir dado local
        int i;

        // especificar acoes da tarefa
        putBeepers(3);
        turnLeft();
        moveN(6);
        turnRight();
        moveN(5);
        turnRight();
        move();
        turnRight();
        moveN(2);
        turnLeft();
        moveN(3);
        turnAround();
        pickBeepers(6);
        moveN(3);
        turnRight();
        moveN(2);
        turnRight();
        moveN(3);
        putBeepers(1);
        move();
        turnRight();
        moveN(4);
        turnRight();
        move();
        putBeepers(2);
        moveN(4);
        turnRight();
        move();
        turnAround();
        putBeepers(3);
        moveN(2);
        turnLeft();
        moveN(6);
        turnLeft();

        // encerrar
        turnOff(); // desligar-se
    }
};