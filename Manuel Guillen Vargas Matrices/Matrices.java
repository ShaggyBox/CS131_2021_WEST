import java.util.Arrays;

public class Matrices {

	public static void main(String[] args) {
		int[][] matrixA = {
						  {4, 5, 3, 1},
						  {9, 6, 4, 2},
						  {5, 8, 2, 3}
						  };
		int[][] matrixB = {
							{7, 3, 1, 8},
							{2, 4, 9, 6},
							{5, 1, 3, 4},
							{3, 2, 1, 3}
							};
		if(validateMatrices(matrixA, matrixB)) {
			multiplyMatrices(matrixA, matrixB);
		} else {
			System.out.println("Matrices of incorrect dimensions");	
		}
	}
	
	public static boolean validateMatrices(int[][] matrixA, int[][] matrixB) {
		int column = matrixA[0].length;
		int row = matrixB.length;
		if(row == column) {
			return true;
		} else {
			return false;
		}
	}
	
	public static void multiplyMatrices(int[][] matrixA, int[][] matrixB) {
		int column = matrixA[0].length - 1;
		int[][] resultingMatrix = new int[matrixA.length][matrixB[0].length];
		for(int i = 0; i < column; i++) {
			for(int j = 0; j < matrixB[0].length; j++) {
				int sum = 0;
				for(int k = 0; k < matrixB.length; k++) {
					sum += matrixA[i][k] * matrixB[k][j];
				}
				resultingMatrix[i][j] = sum;
			}
		}
		System.out.println(Arrays.deepToString(resultingMatrix));
	}
}
