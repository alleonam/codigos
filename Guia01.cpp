/*
 * Guia01 - v1.4. - 16 / 02 / 2023
 * Author: Manoella Santos Diniz
 */

// lista de dependencias
#include "karel.hpp"

// --------------------------- definicoes de metodos

/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    int i;

    // colocar paredes no mundo
    for (i = 3; i < 6; i++)
    {
        world->set(i, 2, HWALL);
        world->set(i, 6, HWALL);
        world->set(5, i, VWALL);
    }

    for (i = 3; i < 7; i++)
    {
        world->set(2, i, VWALL);
    }

    // colocar um marcador no mundo
    world->set(2, 3, BEEPER);
    world->set(6, 3, BEEPER);
    world->set(3, 7, BEEPER);

    // salvar a configuracao atual do mundo
    world->save(fileName);
}

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
     * doTask - Relacao de acoes para qualquer robo executar.
     */
    void doTask()
    {
        // definir dado local
        int i;

        // especificar acoes da tarefa
        move();
        turnLeft();
        moveN(2);

        if (nextToABeeper())
            pickBeeper();

        moveN(4);
        turnRight();
        move();

        if (nextToABeeper())
            pickBeeper();

        moveN(3);
        turnRight();
        moveN(4);
        turnAround();

        if (nextToABeeper())
            pickBeeper();

        moveN(3);
        turnLeft();
        moveN(2);
        turnLeft();
        moveN(3);
        turnAround();

        while (nbeepers() > 0)
        {
            putBeeper();
        }

        moveN(3);
        turnRight();
        moveN(2);

        for (i = 0; i < 2; i++)
        {
            turnRight();
            moveN(5);
        }

        turnAround();

        // encerrar
        turnOff(); // desligar-se
    }
};

// --------------------------- acao principal

/**
 * Acao principal: executar a tarefa descrita acima.
 */
int main()
{
    // definir o contexto

    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    //       antes de qualquer outra coisa
    //       (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0114.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0114.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual

    set_Speed(3); // definir velocidade padrao

    // criar robo
    MyRobot *robot = new MyRobot();

    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");

    // executar tarefa
    robot->doTask();

    // encerrar operacoes no ambiente
    world->close();

    // encerrar programa
    getchar();
    return (0);
}

// ------------------------------------------- testes

/*
 *
 * ---------------------------------------------- documentacao complementar
 *
 * ---------------------------------------------- notas / observacoes / comentarios
 *
 * ---------------------------------------------- previsao de testes
 *
 * v1.1 - 01. o robo ira deslocar e colocar os
 *            marcadores de acordo com as repeticoes
 *
 * v1.2 - 01. o robo ira deslocar e pegar os
 *            marcadores de acordo com as repeticoes
 *
 * v1.3 - 01. o robo ira deslocar, pegar os
 *            marcadores de acordo com as repeticoes
 *            e colocar nos pontos definidos
 *
 * v1.4 - 01. o robo ira deslocar, desviar das
 *            paredes e pegar o marcador
 *
 * ---------------------------------------------- historico
 *
 * Versao   Data    Modificacao
 * 0.1      16/02   esboco
 * 0.2      16/02   adicao do metodo doTask()
 * 0.3      16/02   adicao do metodo doPartialTask()
 * 0.4      16/02   adicao do metodo pickBeeper()
 * 0.5      16/02   adicao do metodo putBeeper()
 * 0.6      16/02   adicao do metodo moveN()
 * 0.7      16/02   testes dos marcadores com o metodo beepersInBag()
 * 0.8      16/02   teste com quantidade
 * 0.9      16/02   adicao de while() para a repeticao do movimento
 * 1.0      16/02   adicao de for() para a repeticao do movimento
 * 1.1      16/02   novo conjunto de acoes
 * 1.2      16/02   novo conjunto de acoes
 * 1.3      16/02   novo conjunto de acoes
 * 1.4      16/02   criacao de uma caixa
 *
 * ---------------------------------------------- testes
 *
 * Versao   Teste
 * 0.1      01. ( OK )  teste inicial
 * 0.2      01. ( OK )  teste da tarefa
 * 0.3      01. ( OK )  teste da tarefa parcial
 * 0.4      01. ( OK )  teste do apanhar marcador
 * 0.5      01. ( OK )  teste do colocar marcador
 * 0.6      01. ( OK )  teste da repeticao do movimento
 * 0.7      01. ( OK )  teste com marcador na posicao (4, 4)
 *          02. ( OK )  teste sem marcador na posicao (4, 4)
 * 0.8      01. ( OK )  teste com a quantidade de marcadores
 * 0.9      01. ( OK )  teste com outra forma de repeticao
 * 1.0      01. ( OK )  teste com outra forma de alternativa
 * 1.1      01. ( OK )  teste das novas acoes
 * 1.2      01. ( OK )  teste das novas acoes
 * 1.3      01. ( OK )  teste das novas acoes
 * 1.4      01. ( OK )  teste da caixa
 *
 */